class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> m;
        for(auto t:nums)
        {
            m[t]++;
        }
        int ans=0;
        for(auto t:m)
        {
            if(t.second<2)
            {
                return -1;
            }
                if(t.second%3==0)
                {
                    ans+=t.second/3;
                }
                else if(t.second%3==2)
                {
                    ans+=t.second/3;
                    ans++;
                }
                else if(t.second%3==1)
                {
                    ans+=2;
                    ans+=(t.second-4)/3;
                }
            }
        return ans;
        }
};