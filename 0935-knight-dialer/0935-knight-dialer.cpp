const int MOD=1e9+7;
int n, m;
int dx[]={-2,-1,1,2,-2,-1, 1, 2};
int dy[]={1 , 2,2,1,-1,-2,-2,-1};

bool isvalid(int x, int y)
{
    if(x==4&&y==2)
    {
        return true;
    }
    if (x < 1 || x > n || y < 1 || y > m )
    {
        return false;
    }
    return true;
}

int dp[5][5][5001];

int dfson2d(int x, int y,int k)
{
    if(k==0)
    {
        return 1;
    }
    if(dp[x][y][k]!=-1)
    {
        return dp[x][y][k];
    }
    int cc=0;
    for (int i = 0; i < 8; i++)
    {
        int x1=x+dx[i];
        int y1=y+dy[i];
        if (isvalid(x1, y1))
        {
            cc+=dfson2d(x1, y1,k-1);
            cc%=MOD;
        }
    }
    return dp[x][y][k] = cc;
}


class Solution {
public:
    int knightDialer(int x) {
        n=3,m=3;
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
            {
                ans+=dfson2d(i,j,x-1);
                ans%=MOD;
            }
        }
        ans+=dfson2d(4,2,x-1);
        ans%=MOD;
        return ans;
    }
};