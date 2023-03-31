const int MOD=1e9+7;
typedef long long ll;

class NumMatrix {
public:
    int dp[51][51];
    int n,m;
    NumMatrix(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j]=matrix[i-1][j-1]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int a, int b, int c, int d) {
        return dp[c+1][d+1]+dp[a][b]-dp[a][d+1]-dp[c+1][b];
    }
};

int n,m;
ll dpp[51][51][11];
ll sum(ll i,ll j,ll rem,NumMatrix &d)
{
    if(i==n||j==m)
    {
        return 0;
    }
    
    if(rem==0)   
    {
        return (d.sumRegion(i,j,n-1,m-1)>0);
    }
    
    if(d.sumRegion(i,j,n-1,m-1)<=rem)
    {
        return 0;
    }
    auto &x=dpp[i][j][rem];
    if(x!=-1)
    {
        return x;
    }
    ll ans=0;
    // move j left
    for(int idx=j;idx<m;idx++)
    {
        // calculate the sum
        int curr=d.sumRegion(i,j,n-1,idx);
        if(curr>0)
        {
            // one of the ways to split
            ans+=sum(i,idx+1,rem-1,d);
            ans%=MOD;
        }
    }
    // move i down
    for(int idx=i;idx<n;idx++)
    {
        int curr=d.sumRegion(i,j,idx,m-1);
        if(curr>0)
        {
            ans+=sum(idx+1,j,rem-1,d);
            ans%=MOD;
        }
    }
    ans%=MOD;
    return x = ans;
}


class Solution {
public:
    int ways(vector<string>& a, int k) {
        n=a.size(),m=a[0].size();
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='.')
                {
                    arr[i][j]=0;
                }
                else
                {
                    arr[i][j]=1;
                }
            }
        }
        NumMatrix d(arr);
        memset(dpp,-1,sizeof(dpp));
        return sum(0,0,k-1,d);
    }
};