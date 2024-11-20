#include <bits/stdc++.h>
using namespace std;
void calculateZArray(string str)
{
    int N = str.length();
    vector<int> Z(N + 1, 0);
    int L = 0, R = 0;
    for (int i = 1; i < N; ++i)
    {
        if (i > R)
        {
            L = R = i;
            while (R < N && str[R - L] == str[R])
            {
                R++;
            }
            Z[i] = R - L;
            R--;
        }
        else
        {
            int k = i - L;
            if (Z[k] < R - i + 1)
            {
                Z[i] = Z[k];
            }
            else
            {
                L = i;
                while (R < N && str[R - L] == str[R])
                {
                    R++;
                }
                Z[i] = R - L;
                R--;
            }
        }
    }
    for (int i = 0; i < N; i++)
        cout << Z[i] << ' ';
    cout << endl;
}
void buildLPSArray(string pat)
{
    int M = pat.size();
    vector<int> lps(M + 1, 0);
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    for (int ii = 0; ii < i; ii++)
        cout << lps[ii] << ' ';
    cout << endl;
}
int main()
{
    string txt = "ABABCABAB";
    string pat = "ABA";
    calculateZArray(txt);
    buildLPSArray(pat);
    return 0;
}