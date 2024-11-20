#include <bits/stdc++.h>
using namespace std;
int ar[100001];
int arr[100001];
int tree[401000];
void coordinateCompression(int ar[], int n)
{
  set<int> s;
  for (int i = 1; i <= n; i++)
  {
    s.insert(ar[i]);
  }
  int index = 0;
  map<int, int> mp;
  set<int>::iterator itr;
  for (itr = s.begin(); itr != s.end(); itr++)
  {
    index++;
    mp[*itr] = index;
  }
  for (int i = 1; i <= n; i++)
  {
    ar[i] = mp[ar[i]];
  }
}

int qurey(int node, int st, int end, int l, int r)
{
  if (st > r || end < l)
    return 0;
  if (st >= l && end <= r)
    return tree[node];
  int mid = (st + end) / 2;
  return max(qurey(2 * node, st, mid, l, r), qurey(2 * node + 1, mid + 1, end, l, r));
}
void update(int node, int st, int end, int pos, int val)
{
  if (st > pos || end < pos)
    return;
  if (pos == st && pos == end)
  {
    tree[node] = val;
    return;
  }
  int mid = (st + end) / 2;
  update(2 * node, st, mid, pos, val);
  update(2 * node + 1, mid + 1, end, pos, val);
  tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  int cnt = 0;
  while (tt--)
  {
    int n;
    cin >> n;
    int ans = -1;
    for (int i = 1; i <= n; i++)
      cin >> ar[i];
    coordinateCompression(ar, n);
    int ax1[n + 2];
    for (int i = 1; i <= n; i++)
    {
      int mx = qurey(1, 1, n, 1, ar[i] - 1);

      update(1, 1, n, ar[i], mx + 1);
      arr[ar[i]] = max(mx + 1, arr[ar[i]]);
      ax1[i] = mx + 1;
    }
    for(int i=1;i<=n;i++) cout<<ax1[i]<<' ';// lis for each index i 
  }
}
