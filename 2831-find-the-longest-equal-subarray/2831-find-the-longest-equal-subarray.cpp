int check(unordered_map<int,vector<int>> &adj,int k)
{
    int ans=1;
    for(auto t:adj)
    {
        auto &v=t.second;
        int sum=0;
        int i=0;
        for(int j=0;j<v.size();j++)
        {
            sum+=v[j];
            while(sum>k)
            {
                sum-=v[i++];
            }
            if(sum<=k)
            {
                ans=max(ans,j-i+2);
            }
        }
    }
    return ans;
}


class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<nums.size();i++)
        {
            adj[nums[i]].push_back(i);
        }
        for(auto &t:adj)
        {
            auto &v=t.second;
            vector<int> curr;
            for(int i=0;i<v.size()-1;i++)
            {
                curr.push_back(v[i+1]-v[i]-1);
            }
            t.second=curr;
        }
        return check(adj,k);
    }
};