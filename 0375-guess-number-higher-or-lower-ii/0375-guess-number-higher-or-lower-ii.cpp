int dp[201][201];
int build(int i,int j)
{
    if(i>=j)
    {
        return 0;
    }
    auto &x=dp[i][j];
    if(x!=-1)
    {
        return x;
    }
    int ans=1e9;
    for(int k=i;k<=j;k++)
    {
        ans=min({ans,max(build(i,k-1),build(k+1,j))+k});
    }
    return x = ans;
}

class Solution {
public:
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof(dp));
        return build(1,n);
    }
};