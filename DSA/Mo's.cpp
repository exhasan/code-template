#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
struct query
{
    int l;
    int r;
    int indx;
} q[200001];
int ans[200001];
int ar[200001];
int fre[200001];
int fre2[200001];
int sum = 0;
int k;
bool compair(query &a, query &b)
{
    int block_a = a.l / k;
    int block_b = b.l / k;
    if (block_a != block_b)
        return block_a < block_b;
    return block_a & 1 ? a.r < b.r : a.r > b.r;
}
void add(int x)
{
    fre2[fre[x]]--;
    fre[x]++;
    fre2[fre[x]]++;
    sum = max(sum, fre[x]);
}
void delet(int x)
{
    fre2[fre[x]]--;
    fre[x]--;
    if (fre2[sum] == 0)
        sum--;
    fre2[fre[x]]++;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int tt;
   // cin >> tt;
 //   while (tt--)
    {
        int c_l = 1;
        int c_r = 0;
        cin >> n;
        int l;
        int r;
        int qq;
        cin >> qq;
        k = ceil(sqrt((n * n) / qq));
        if (k == 0)
            k = 1;
        ar[0] = 0;
        int mi = 1e16;
        for (int i = 1; i <= n; i++)
        {
            cin >> ar[i];
        }
        for (int i = 0; i < qq; i++)
        {
            cin >> q[i].l;
            cin >> q[i].r;
            q[i].r++;
            q[i].l++;
            q[i].indx = i;
        }
        sort(q, q + qq, compair);
        for (int i = 0; i < qq; i++)
        {
            while (c_r < q[i].r)
            {
                add(ar[++c_r]);
            }
            while (c_l > q[i].l)
            {
                add(ar[--c_l]);
            }
            while (c_r > q[i].r)
            {
                delet(ar[c_r--]);
            }
            while (c_l < q[i].l)
            {
                delet(ar[c_l++]);
            }
            ans[q[i].indx] =sum;
        }
        for (int i = 0; i < qq; i++)
            cout << ans[i] << endl;
    }
}
// https://www.spoj.com/problems/FREQ2/