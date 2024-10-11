#include <bits/stdc++.h>
#define endl '\n'
#define int long long int
using namespace std;
#define N 200010
int sz[N];
int heavy[N];
int par[N];
int depth[N];
int head[N];
int lt[N];
int pos[N];
int val[N];
int indx;
int tree[2 * N + 10];
int n;
void build()
{
    for (int i = n - 1; i > 0; --i)
        tree[i] = (tree[i << 1] + tree[i << 1 | 1]);
}

void update(int p, int value)
{
    for (tree[p += n - 1] = value; p > 1; p >>= 1)
    {
        int x = p >> 1;
        tree[p >> 1] = (tree[p] + tree[p ^ 1]);
    }
}

int query(int l, int r)
{
    int res = 0;
    for (l += n - 1, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = (res + tree[l++]);
        if (r & 1)
            res = (res + tree[--r]);
    }
    return res;
}
vector<vector<int>> adj;
void dfs(int node)
{
    for (auto child : adj[node])
    {
        if (child == par[node])
            continue;
        depth[child] = depth[node] + 1;
        par[child] = node;
        dfs(child);
        sz[node] += sz[child];
        if (sz[child] > sz[heavy[node]])
            heavy[node] = child;
    }
    sz[node]++;
}
void dfs_HLD(int node, int chain, int parr)
{
    indx++;
    head[node] = chain;
    pos[node] = indx;
    lt[indx] = val[node];
    if (heavy[node] != 0)
    {
        dfs_HLD(heavy[node], chain, par[heavy[node]]);
    }
    for (auto child : adj[node])
    {
        if (child == parr)
            continue;
        if (heavy[node] != child)
        {
            dfs_HLD(child, child, par[child]);
        }
    }
}
int lca(int a, int b)
{
    while (head[a] != head[b])
    {
        if (depth[head[a]] > depth[head[b]])
            a = par[head[a]];
        else
            b = par[head[b]];
    }
    return (depth[a] < depth[b]) ? a : b;
}
int path_query(int a, int b)
{
    int ans = 0;
    while (head[a] != head[b])
    {
        if (depth[head[a]] < depth[head[b]])
            swap(a, b);
        ans = (ans + query(pos[head[a]], pos[a]));
        a = par[head[a]];
    }
    if (depth[a] < depth[b])
    {
        int t;
        t = a, a = b, b = t;
    }
    ans = (ans + query(pos[b], pos[a]));
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt;
    cin >> tt;
    for (int ii = 1; ii <= tt; ii++)
    {
        int q;
        cin >> n;
        adj.resize(n + 2);
        for (int i = 1; i <= n; i++)
            cin >> val[i];
        for (int i = 1; i < n; i++)
        {
            int x, y, w;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(1);
        dfs_HLD(1, 1, 0);
        for (int i = 1; i <= n; i++)
            tree[n + i - 1] = lt[i];
        build();
        cin >> q;
        cout << "Case " << ii << ":" << endl;
        while (q--)
        {
            int k, a, b;
            cin >> k >> a >> b;
            if (k == 0)
            {
                cout << path_query(a, b) << endl;
            }
            else
            {
                update(pos[a], b);
            }
        }
        adj.clear();
        indx = 0;
        for (int i = 1; i <= 2 * n + 2; i++)
        {
            tree[i] = 0;
            if (i > n)
                continue;
            depth[i] = 0;
            sz[i] = 0;
            heavy[i] = 0;
            head[i] = 0;
            lt[i] = 0;
            pos[i] = 0;
            par[i] = 0;
        }
    }
}
// https://cses.fi/problemset/task/2134/