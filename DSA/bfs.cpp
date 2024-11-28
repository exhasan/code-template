#include<bits/stdc++.h>
using namespace std;

int vis[100];
 vector<vector<int>>adj;
void dfs(int n)
{
  queue<int>st;
  st.push(n);
  vis[n]=1;
  while(!st.empty())
  {
     int u = st.front();
     cout<<u<<' ';
     st.pop();
     for(auto x: adj[u])
     {
         if(vis[x]==0)
         {
            st.push(x);
            vis[x]=1;
         }
     }
  }
}
int main()
{
    int n,m;
    cin>>n>>m;
    adj.resize(n+2);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<i<<"->"<<' ';
        for(auto x: adj[i]) cout<<x<<' '; cout<<endl;
    }
    cout<<endl;
    dfs(1);
}