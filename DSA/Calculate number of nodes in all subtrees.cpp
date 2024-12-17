vector<vector<int>> adj;
int cnt[200001];
void dfs(int s, int e)
{
    cnt[s] = 1;
    for(auto u : adj[s]  {
        if (u != e)
        {
            dfs(u, s);
            cnt[s] += cnt[u];
        }  }
}
