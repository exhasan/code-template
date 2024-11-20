#include <bits/stdc++.h>
using namespace std;
long long int ar[1000001];
void s(long long L, long long R)
{
    for (int i = 0; i < R - L + 1; i++)
        ar[i] = true;
    // isPrime(R - L + 1, true);
    long long lim = sqrt(R);
    for (long long i = 2; i <= lim; ++i)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            ar[j - L] = false;
    if (L == 1)
        ar[0] = false;
    for (int i = 0; i <= R - L; i++)
    {
        if (ar[i] == 1)
            cout << L + i << '\n';
    }
    // return isPrime;
}
int main()
{
    long long a, b, c, d, e, f;
    int t, n;
    long long int sum = 0;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        s(a, b);
    }
}
