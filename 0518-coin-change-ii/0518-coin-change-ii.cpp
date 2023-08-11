class Solution {
public:
    int dp[301][5001];
    int changer(int idx,int amount, vector<int>& coins) {
        if(amount==0)
        {
            return 1;
        }
        if(idx==coins.size())
        {
            return 0;
        }
        auto &x=dp[idx][amount];
        if(x!=-1)
        {
            return x;
        }
        int ans=0;
        ans += changer(idx+1,amount,coins);
        if(coins[idx] <= amount)
        {
            ans+=changer(idx,amount-coins[idx],coins);
        }
        return x = ans;
    }
    
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return changer(0,amount,coins);
    }
};