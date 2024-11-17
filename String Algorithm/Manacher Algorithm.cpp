#include <bits/stdc++.h>
#define int long long int
using namespace std;
vector<int> manachers(string s)
{
    string ss;
    for (auto x : s)
    {
        ss += '#';
        ss += x;
    }
    ss += '#';
    int n = ss.size();
    s = '$' + ss + '^';
    int l = 1;
    int r = 1;
    vector<int> len(n + 2);
    for (int i = 1; i <= n; i++)
    {
        len[i] = min(r - i, len[l + (r - i)]);
        while (s[i - len[i]] == s[i + len[i]])
            len[i]++;
        if (i + len[i] > r)
        {
            l = i - len[i];
            r = i + len[i];
        }
    }
    return len;
}
int32_t main()
{
    int n;
    cin >> n;
    string s;
    int tt;
    // cin>>tt;
    //  while(tt--)
    {
        cin >> s;
        vector<int> vt = manachers(s);
        int mx = -1;
        int cen = -1;
        for (int i = 0; i < vt.size(); i++)
        {
            if (vt[i] > mx)
            {
                mx = vt[i];
                cen = i;
            }
        }
        mx--;
        string ans;
        int l, r;
        if (cen % 2 == 0)
        {
            cen = cen / 2 - 1;
            l = cen - mx / 2;
            r = cen + mx / 2;
        }
        else
        {
            cen--;
            cen = (cen / 2) - 1;
            l = cen - mx / 2 + 1;
            r = cen + mx / 2;
        }
        map<char, int> mp;
        for (int i = 0; i < l; i++)
            mp[s[i]]++;
        for (int i = r + 1; i < s.size(); i++)
            mp[s[i]]++;
        int cnt = 0;
        for (auto x : mp)
            if (x.second % 2 == 1)
                cnt++;
        cout << cnt << endl;
        vt.clear();
    }
}
