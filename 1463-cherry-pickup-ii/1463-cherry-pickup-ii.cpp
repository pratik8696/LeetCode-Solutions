int n,m;

bool isvalid(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m)
    {
        return false;
    }
    return true;
}

int dp[80][80][80];

int sum(int row,int j1,int j2,vector<vector<int>> &arr)
{
    if(row==n)
    {
        return 0;
    }
    auto &x=dp[row][j1][j2];
    if(x!=-1)
    {
        return x;
    }
    int ans=0;
    if(j1==j2)
    {
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                int x1=j1+i,x2=j2+j;
                if(isvalid(row,x1) && isvalid(row,x2))
                {
                    ans=max(ans,sum(row+1,x1,x2,arr)+arr[row][j1]);
                }
            }
        }        
    }
    else
    {
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                int x1=j1+i,x2=j2+j;
                if(isvalid(row,x1)&&isvalid(row,x2))
                {
                    ans=max(ans,sum(row+1,x1,x2,arr)+arr[row][j1]+arr[row][j2]);
                }
            }
        }
    }
    return x = ans;
}

class Solution {
public:
    int cherryPickup(vector<vector<int>>& arr) {
        n=arr.size(),m=arr[0].size();
        memset(dp,-1,sizeof(dp));
        return sum(0,0,m-1,arr);
    }
};