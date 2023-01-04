class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> m;
        for(auto t:tasks)
        {
            m[t]++;
        }
        int ans=0;
        for(auto t:m)
        {
            if(t.second==1)
            {
                return -1;
            }
            ans+=(t.second+2)/3;
        }
        return ans;
    }
};
