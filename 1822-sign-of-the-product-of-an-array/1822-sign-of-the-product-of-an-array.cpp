class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cc=0;
        for(auto t:nums)
        {
            if(t<0)
            {
                cc++;
            }
            if(t==0)
            {
                cc=-1e9;
            }
        }
        if(cc<0)
        {
            return 0;
        }
        if(cc%2==0)
        {
            return 1;
        }
        return -1;
    }
};