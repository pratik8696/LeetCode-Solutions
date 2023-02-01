class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,multiset<int>> m;
        for(auto t:nums)
        {
            auto &x=m[t-1];
            if(x.size())
            {
                int temp=*x.begin();
                x.erase(x.begin());
                m[t].insert(temp+1);
            }
            else
            {
                m[t].insert(1);
            }
            
        }
        
        for(auto t:m)
        {
            // cout<<t.first<<" -> ";
            for(auto x:t.second)
            {
                if(x<3)
                {
                    return false;
                }
                // cout<<x<<" ";
            }
            // cout<<endl;
            
        }        
        return true;
    }
};