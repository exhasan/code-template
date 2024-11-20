#include<bits/stdc++.h>
using namespace std;
vector<int>LIS(const vector<int> &elements)
{
    auto compare = [&](int x,int y)
    {
        return elements[x]>elements[y];
    };
    set<int,decltype(compare)>S(compare);
    vector<int>previous(elements.size(),-1);
    for(int i=0; i<elements.size();++i)
    {
        auto it=S.insert(i).first;
        if(it!=S.begin())
            previous[i]=*prev(it);
        if(*it==i&&next(it)!=S.end())
            S.erase(next(it));
    }
    vector<int>answer;
    answer.push_back(*S.rbegin());
    while(previous[answer.back()]!=-1)
        answer.push_back(previous[answer.back()]);
    reverse(answer.begin(),answer.end());
    return answer;
}
int main()
{
    vector<int>vat;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        vat.push_back(x);
    }
    vector<int> LIS_elements=LIS(vat);
    cout<<LIS_elements.size()<<endl;
     for(auto x: LIS_elements) cout<<x<<' '; cout<<endl;
    return 0; 
    
}
