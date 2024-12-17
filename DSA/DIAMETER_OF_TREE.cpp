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
                dis[y] = dis[x] + 1;
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
    dfs(1);
    int g = -1;
    int a;
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] > g)
        {
            g = dis[i];
            a = i;
        }
    }
    memset(dis, 0, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dfs(a);
    g = -1;
    int b;
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] > g)
        {
            g = dis[i];
            b = i;
        }
    }
    cout << a << ' ' << b << ' ' << g << endl;
}
