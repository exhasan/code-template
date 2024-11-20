#include<bits/stdc++.h>
using namespace std;
int phi(int n)
{
    int ans = n;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
                n/=i; 
            ans -= ans/i;
        }
    }
    if(n>1) ans -= ans/n;
    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<phi(n);
    return 0;
}
/*
The Euler's Totient Function, denoted as 𝜙(𝑛)
is a mathematical function that counts the number of integers between  1 and n that are coprime with n.
*/