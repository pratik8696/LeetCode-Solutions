int dp[101][101][201];
bool sum(int idx1,int idx2,int idx3,string &a,string &b,string &c)
{
    if(idx3==c.length())
    {
        if(idx1==a.length() && idx2==b.length())
            return true;
        else
            return false;
    }
    auto &x=dp[idx1][idx2][idx3];
    if(x!=-1)
    {
        return x;
    }
    bool ans=false;
    if(idx1<a.length()&&a[idx1]==c[idx3])
    {
        ans|=sum(idx1+1,idx2,idx3+1,a,b,c);
    }
    if(idx2<b.length()&&b[idx2]==c[idx3])
    {
        ans|=sum(idx1,idx2+1,idx3+1,a,b,c);
    }
    return x=ans;
}

class Solution {
public:
    bool isInterleave(string a, string b, string c) 
    {
        memset(dp,-1,sizeof(dp));
        return sum(0,0,0,a,b,c);
    }
};