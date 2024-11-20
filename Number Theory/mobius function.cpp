#include <bits/stdc++.h>
using namespace std;
#define int long long int
short mu[1000005] = {0, 1};
int cnt[1000005];
int cnt1[1000005];
int vis[500001];
void fun()
{
    for (int i = 1; i <= 500001; i++)
    {
        if (mu[i])
        {
            for (int j = i + i; j <= 500001; j += i)
            {
                mu[j] -= mu[i];
            }
        }
    }
}

int32_t main()
{

    int n;
    cin >> n;
    int q;
    cin >> q;
    fun();
    int ar[n + 2];
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> ar[i];
        mx = max(mx, ar[i]);
    }
    vector<vector<int>> adj;
    vector<vector<int>> adj1;
    adj.resize(mx + 2);
    adj1.resize(mx + 2);
    for (int i = 1; i <= mx; i++)
    {
        for (int j = i; j <= mx; j = j + i)
        {
            adj[j].push_back(i);
            adj1[i].push_back(j);
        }
    }

    int ans = 0;

    while (q--)
    {
        int x;
        cin >> x;

        if (vis[x] == 0)
        {
            vis[x] = 1;

            for (int i = 0; i < adj[ar[x]].size(); i++)
            {
                int px = adj[ar[x]][i];

                {
                    if (mu[px] == -1)
                        ans -= cnt[px];
                    else if (mu[px] == 1)
                        ans += cnt[px];
                    cnt[px]++;
                }
            }
        }
        else
        {

            vis[x] = 0;
            for (int i = 0; i < adj[ar[x]].size(); i++)
            {
                int px = adj[ar[x]][i];

                cnt[px]--;
                {
                    if (mu[px] == -1)
                        ans += cnt[px];
                    else if (mu[px] == 1)
                        ans -= cnt[px];
                }
            }
        }

        cout << ans << endl;
    }
}
// https://codeforces.com/contest/547/problem/C 