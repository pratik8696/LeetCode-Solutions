class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev=0;
        int ans=0;
        for(auto t:bank)
        {
            int curr=0;
            for(auto x:t)
            {
                curr+=(x=='1');
            }
            if(curr)
            {
                ans+=prev*curr;
                prev=curr;
            }
        }
        return ans;
    }
};