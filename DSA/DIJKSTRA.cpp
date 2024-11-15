void dijkstra (int source)
{
      priority_queue<pair<long long int ,long long int >, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>>q;
  // priority_queue<pair<long long int ,long long int >>q;
    q.push({0,source});
    dis[source]=0;
    while(!q.empty())
    {
        long long int  a=q.top().first;
        long long int  b=q.top().second;
         q.pop();
        if(vis[b]) continue;
        vis[b]=1;
        for(auto x:g[b])
        {
            long long int  v=x.first;
            long long int  u=x.second;
            if(dis[b]+v<dis[u])
            {
               // cout<<u<<endl;
                dis[u]=dis[b]+v;
                q.push({dis[u],u});
                path[u]=b;
            }
        }
    }
}
