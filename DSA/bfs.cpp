#include <bits/stdc++.h>
using namespace std;

int vis[100];
vector<vector<int>> adj;
void dfs(int start)
{
    queue<int> qu;
    qu.push(start);
    vis[start] = 1;
    while (!qu.empty())
    {
        int parent = qu.front();
        cout << parent << ' ';
        qu.pop();
        for (auto child : adj[parent])
        {
            if (vis[child] == 0)
            {
                qu.push(child);
                vis[child] = 1;
            }
        }
    }
}
int main()
{
    int node, edge;
    cin >> node >> edge;
    adj.resize(node + 2);
    for (int i = 1; i <= edge; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= node; i++)
    {
        cout << i << "->" << ' ';
        for (auto x : adj[i])
            cout << x << ' ';
        cout << endl;
    }
    cout << endl;
    dfs(1);
}