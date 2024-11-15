#include <bits/stdc++.h>
#define int long long int
#define endl '\n'
using namespace std;
int level[200001];
int vis[200001];
int lev = 18;
int far[21][200001];
int ar[200001];
vector<vector<int>> adj;
void bfs(int x)
{
  ar[x] = x;
  queue<int> q;
  q.push(x);
  vis[x] = 1;
  level[x] = 0;
  while (!q.empty())
  {
    int x = q.front();
    q.pop();
    for (auto xx : adj[x])
    {
      if (!vis[xx])
      {
        ar[xx] = x;
        q.push(xx);
        vis[xx] = 1;
        level[xx] = level[x] + 1;
      }
    }
  }
}
int lifting(int k, int x)
{
  for (int i = lev; i >= 0; i--)
  {
    if ((1 << i) <= k)
    {
      x = far[i][x];
      k = k - (1 << i);
    }
  }
  return x;
}
int get_lca(int a, int b)
{
  if (level[a] < level[b])
    swap(a, b);
  int k = level[a] - level[b];
  a = lifting(k, a);
  if (a == b)
    return a;
  for (int i = lev; i >= 0; i--)
  {
    if (far[i][a] != far[i][b])
    {
      a = far[i][a];
      b = far[i][b];
    }
  }
  return far[0][a];
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--)
  {
    int n;
    int qu;
    cin >> n;
    adj.resize(n + 1);
    adj[0].push_back(0);
    for (int i = 1; i < n; i++)
    {
      int x, y;
      cin >> x >> y;
      x--, y--;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    ar[0] = 0;// store parent in this array (0 base)
    bfs(0);

    for (int i = 1; i < n; i++)
    {
      far[0][i] = ar[i];
    }
    for (int i = 1; i <= lev; i++)
      for (int j = 1; j <= n; j++)
        far[i][j] = far[i - 1][far[i - 1][j]];

    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
      int x, y;
      cin >> x >> y;
      x--, y--;
      int lc = get_lca(x, y);
      // cout << lc+1 << endl;
      int tot = abs(level[lc] * 2 - level[x] - level[y]);
      tot = tot / 2;

      if (tot <= abs(level[lc] - level[x]))
        cout << lifting(tot, x) + 1 << endl;
      else
      {
        int y_d = abs(level[lc] - level[y]);
        y_d = y_d - (tot - abs(level[lc] - level[x]));
        cout << lifting(y_d, y) + 1 << endl;
      }
    }
    adj.clear();
    for(int i=0;i<=n;i++)
    {
      level[i]=0;
      vis[i]=0;
    }
  }
