bool check(int val,unordered_map<int,vector<int>> &adj,int k)
{
    for(auto t:adj)
    {
        auto &v=t.second;
        // cout<<t.first<<": ";
        if(v.size()>=val)
        {
            int sum=0;
            for(int i=0;i<val;i++)
            {
                sum+=v[i];
            }   
            // cout<<sum<<", ";
            if(sum<=k)
            {
                return true;
            }
            int i=0;
            for(int j=val;j<v.size();j++)
            {
                
                sum+=v[j];
                sum-=v[i++];
                // cout<<sum<<", ";
                if(sum<=k)
                {
                    return true;
                }
            }
        }
        // cout<<endl;
    }
    return false;
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
        int i=2,j=nums.size(),ans=1;
        // cout<<check(1,adj,k)<<endl;
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(check(mid-1,adj,k))
            {
                i=mid+1;
                ans=mid;
            }
            else
            {
                j=mid-1;
            }
        }
        return ans;
    }
};