#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
int vis[200001];
int dis[200001];
void dfs(int k)
{
    queue<int> qu;
    qu.push(k);
    vis[k] = 1;
    while (!qu.empty())
    {
        int x = qu.front();
        qu.pop();
        for (auto y : adj[x])
        {
            if (!vis[y])
            {
                vis[y] = 1;
                qu.push(y);
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << endl;
}
