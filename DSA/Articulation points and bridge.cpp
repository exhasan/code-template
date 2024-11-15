#include <bits/stdc++.h>
using namespace std;
int n;                   // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p)
{
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;
    for (int to : adj[v])
    {
        if (to == p)
            continue;
        if (visited[to])
        {
            low[v] = min(low[v], tin[to]);
        }
        else
        {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p != 0)
                cout << v << ' ';
            ++children;
        }
    }
    if (p == -1 && children > 1)
        cout << v << ' ';
}

void find_cutpoints()
{
    timer = 0;
    visited.resize(n + 1, false);
    tin.resize(n + 1, 0);
    low.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
            dfs(i, 0);
    }
}
void dfs1(int v, int p)
{
    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (int to : adj[v])
    {
        if (to == p && !parent_skipped)
        {
            parent_skipped = true;
            continue;
        }
        if (visited[to])
        {
            low[v] = min(low[v], tin[to]);
        }
        else
        {
            dfs1(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                cout << v << ' ' << to << endl;
        }
    }
}

void find_bridges()
{
    timer = 0;
    visited.resize(n + 1, false);
    tin.resize(n + 1, 0);
    low.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
            dfs1(i, 0);
    }
}
int main()
{
    int e;
    cin >> n >> e;
    adj.resize(n + 1);

    for (int i = 1; i <= e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    find_bridges();
}

