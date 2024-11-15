int ax[200001];
vector<int> lst[200001];
void xmake_set(int v)
{
    lst[v] = vector<int>(1, v);
    ax[v] = v;
}

int xfind_set(int v)
{
    return ax[v];
}

void xunion_sets(int a, int b)
{
    a = xfind_set(a);
    b = xfind_set(b);
    if (a != b)
    {
        if (lst[a].size() < lst[b].size())
            swap(a, b);
        while (!lst[b].empty())
        {
            int v = lst[b].back();
            lst[b].pop_back();
            ax[v] = a;
            lst[a].push_back(v);
        }
    }
}
