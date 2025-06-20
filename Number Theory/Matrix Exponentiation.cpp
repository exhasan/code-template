#include <bits/stdc++.h>
#define int long long int
#define endl '\n'
using namespace std;
#define N 2000
int ar[N][N], I[N][N];
#define mod 1000000007
void mul(int A[][N], int B[][N], int n)
{
    int i, j, k;
    int R[n + 1][n + 1];
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            R[i][j] = 0;
            for (k = 1; k <= n; k++)
            {
                int x = (A[i][k] * B[k][j]) % mod;
                R[i][j] = (R[i][j] + x) % mod;
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            A[i][j] = R[i][j];
        }
    }
}
void power(int A[][N], int n, int p)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i == j)
                I[i][j] = 1;
            else
                I[i][j] = 0;
        }
    }
    while (p)
    {
        if (p % 2 == 1)
        {
            mul(I, A, n);
            p--;
        }
        else
        {
            mul(A, A, n);
            p /= 2;
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            A[i][j] = I[i][j];
        }
    }
}
int32_t main()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    n--;
    ar[1][1] = 1, ar[1][2] = 1, ar[2][1] = 1, ar[2][2] = 0;
    power(ar, 2, n);
    cout << ar[1][1] << endl;
}
// // https://codeforces.com/gym/102644/problem/C
