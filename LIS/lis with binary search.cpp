#include<bits/stdc++.h>
using namespace std;
int lengthOfLIS(vector<int>& nums)
{
    vector<int>vt;
    for(int i=0; i<nums.size(); i++)
    {
        if(i==0) vt.push_back(nums[i]);
        else if(vt.back()<nums[i]) vt.push_back(nums[i]);
        else
        {
            auto  pos = lower_bound(vt.begin(),vt.end(),nums[i]);
            int p = pos - vt.begin();
            vt[p]=nums[i];
        }
    }
    return vt.size();

}
