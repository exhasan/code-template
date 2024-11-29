#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef unsigned long long ull;
ull n;
ull mul(ull a,ull n,ull m)
{
    a%=m;
    ull ans = 0;
    while(n)
    {
            if(n&1)
            {
                ans+=a; ans%=m;
            }
            (a*=2)%=m;
            n>>=1;
    }
    return ans;
}
ull exp(ull a,ull n,ull m)
{
    a%=m;
    ull ans = 1;
    while(n)
    {
        if(n&1) ans= mul(ans,a,m);
        a=mul(a,a,m)%m;
        n>>=1;
    }
    return ans;
}
long long int  bigmod(long long int  a, long long int  b, long long int  M)
{
    if(b==0) return 1%M;
    long long int  x = bigmod(a,b/2,M);
    x = (x*x) % M;
    if(b%2 == 1) x = (x*a)%M;
    return x;
}
bool M_R(ull n)
{
     static vector<ull>prime={2,3,5,7,11,13,17,19,23,29,31,37};
    for(auto x: prime)
    {
        if(n==x) return true;
    }
    if(n<=38) return false;
    int k=0;
    ull m= n-1;
    for(;(m&1)^0;m>>=1) k++;
    auto check =[&](ull a,ull n, int  k, ull m)->bool
    {
       ull mod = exp(a,m,n);
      // cout<<a<<' '<<m<<' '<<n<<' '<<mod<<endl;
       if(mod == 1|| mod == n-1) return true;
       for(int i=1;i<k;i++)
       {
           (mod*=mod)%=n;
           if(mod == n-1) return true;
       }
       return false;
    };
    for(auto x: prime) if(!check(x,n,k,m)) return false;
    return true;
}
void solve()
{
    cin>>n;
    if(n==2) cout<<"YES"<<endl;
    else if(n%2==0) cout<<"NO"<<endl;
    else
    cout<<(M_R(n)?"YES":"NO")<<endl;
}
int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
