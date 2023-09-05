class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        unordered_map<int,vector<int>> adj;
        set<int> s;
        for(int i=0;i<nums.size();i++)
        {
            auto &v=nums[i];
            for(int j=0;j<v.size();j++)
            {
                adj[v[j]].push_back(i);
                s.insert(v[j]);
            }
        }
        int i=-1e5;
        unordered_map<int,int> hsh;
        int curr=0,ans=3e5;
        int diff=1e8,left=-1e8,right=1e8;
        vector<int> v(begin(s),end(s));
        for(auto j:v)
        {
            if(adj[j].size())
            {
                for(auto t:adj[j])
                {
                    hsh[t]++;
                    if(hsh[t]==1)
                    {
                        curr++;
                    }
                }
            }
            while(i<=j&&curr==nums.size())
            {
                if(adj[i].size())
                {
                    for(auto t:adj[i])
                    {
                        hsh[t]--;
                        if(hsh[t]==0)
                        {
                            curr--;
                        }
                    }
                }
                if(j-i+1<diff)
                {
                    diff=j-i+1;
                    left=i;
                    right=j;
                }
                ans=min(ans,j-i+1);
                i++;
            }
        }
        cout<<ans<<endl;
        return {left,right};
    }
};