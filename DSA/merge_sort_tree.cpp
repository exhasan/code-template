#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 5e5 + 50;
int ar[N];
vector<int> tree[5 * N];
const long long int inf = 1e14;
int t;
void build(int cur, int l, int r)
{
    if (l == r)
    {
        tree[cur].push_back(ar[l]);
        return;
    }
    int mid = l + (r - l) / 2;
    build(2 * cur, l, mid);
    build(2 * cur + 1, mid + 1, r);
    tree[cur].resize(tree[2 * cur].size() + tree[2 * cur + 1].size());
    merge(tree[2 * cur].begin(), tree[2 * cur].end(),
          tree[2 * cur + 1].begin(), tree[2 * cur + 1].end(),
          tree[cur].begin());
}
pair<int, int> query(int cur, int l, int r, int x, int y, int k)
{
    if (r < x || l > y)
    {
        return {0, inf};
    }
    if (x <= l && r <= y)
    {
        int p = lower_bound(tree[cur].begin(), tree[cur].end(), k) - tree[cur].begin();
        if (p == tree[cur].size())
        {
            return {p, inf};
        }
        if (tree[cur][p] == k)
            return {p, tree[cur][p]};
        return {p, tree[cur][p]};
    }
    int mid = l + (r - l) / 2;
    pair<int, int> a = query(2 * cur, l, mid, x, y, k);
    pair<int, int> b = query(2 * cur + 1, mid + 1, r, x, y, k);
    return {a.first + b.first, min(a.second, b.second)};
}

pair<int, int> query1(int cur, int l, int r, int x, int y, int k)
{
    if (r < x || l > y)
    {
        return {0, -1};
    }
    if (x <= l && r <= y)
    {
        int p = upper_bound(tree[cur].begin(), tree[cur].end(), k) - tree[cur].begin();
        if (p == 0)
        {
            return {0, -1};
        }
        return {p, tree[cur][p - 1]};
    }
    int mid = l + (r - l) / 2;
    pair<int, int> a = query1(2 * cur, l, mid, x, y, k);
    pair<int, int> b = query1(2 * cur + 1, mid + 1, r, x, y, k);
    return {a.first + b.first, max(a.second, b.second)};
}

int main()
{
    int n;
    cin >> n;
    int q;
    cin >> q;
    for (int i = 1; i <= n; i++)
        cin >> ar[i];
    build(1, 1, n);
    while (q--)
    {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        pair<int, int> ans = query(1, 1, n, l, r, x);
        pair<int, int> ans1 = query1(1, 1, n, l, r, y);
        int p = ans1.first - ans.first;
        if (p == 0)
        {
            cout << p << ' ' << -1 << ' ' << -1 << endl;
            continue;
        }
        cout << p << ' ' << ans.second << ' ' << ans1.second << endl;
    }
}
// https://toph.co/p/dengue-affected-areas