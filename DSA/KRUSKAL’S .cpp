#include<bits/stdc++.h>
using namespace std;
long long int ar[200001];
pair<int,pair<long long int,long long int>> ms[200001];
vector<pair<long long int,long long int >>g[100001];
vector<pair<long long int,long long int >>mst[200001];
stack<long long int > st;
int viss[200001];
int vis[200001];
int cnt = 0;
int  solve (int source)
{
    queue<long long int >q;
    q.push(source);
    while(!q.empty())
    {
        long long int  b=q.front(); //GRAPH TRAVERSAL
        q.pop();
        if(viss[b]) continue;
        viss[b]=1; cnt++;
        for(auto x:g[b])
        {
            if(viss[x.second]==0)
            q.push(x.second);
        }
    }
    return cnt;
}
long long int Find(long long int k)
{
    if(ar[k]==k)
        return k;
    return ar[k] = Find(ar[k]);
}
void Union(long long int a,long long int b)
{
    long long int A=Find(a);
    long long int B=Find(b);
    ar[A]=B;
}
void build(long long int n)
{
    for(long long int i=1; i<=n; i++)
        ar[i]=i;
}
int main()
{
    long long int v, e;
    cin >> v >> e;
    for(int i=0; i<e; i++)
    {
        long long int w, u, v;
        cin >> u >> v >> w;
        ms[i].first = w;
        vis[u]=1; vis[v]=1;
        ms[i].second.first = u;
        ms[i].second.second = v;
        g[u].push_back({w,v});
        g[v].push_back({w,u});
    }
    int r= solve(1);
    sort(ms, ms+e); build(v);
    long long int cost=0;
    for(int i=0; i<e; i++)
    {
        long long int a=Find(ms[i].second.first);
        long long int b=Find(ms[i].second.second);
        if(a==b) continue;
        cost=cost+ms[i].first;
        Union(a,b);
        mst[ms[i].second.first].push_back({ms[i].first,ms[i].second.second});
        mst[ms[i].second.second].push_back({ms[i].first,ms[i].second.first});
    }
      cout << cost << endl;
    return 0;
}
