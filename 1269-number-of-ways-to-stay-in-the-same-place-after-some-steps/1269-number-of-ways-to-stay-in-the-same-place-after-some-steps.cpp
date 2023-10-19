typedef long long ll;
int dx[]={1,0,-1};
int sz;
const int MOD=1e9+7;

int isvalid(int x)
{
    if(x<0||x>sz-1)
    {
        return 0;
    }
    return 1;
}



ll sum(int x,int k,vector<vector<int>> &dp)
{
    if(k==0)
    {
        return x==0;
    }
    if(dp[x][k]!=-1)
    {
        return dp[x][k];
    }
    int ans=0;
    for(int i=0;i<3;i++)
    {
        if(isvalid(x+dx[i]))
        {
            ans+=sum(x+dx[i],k-1,dp);
            ans%=MOD;
        }
    }
    ans%=MOD;
    return dp[x][k] = ans;
}


class Solution {
public:
    int numWays(int steps, int arrLen) {
        sz=arrLen;
        vector<vector<int>> dp(steps+1,vector<int>(steps+1,-1));
        return sum(0,steps,dp);
    }
};