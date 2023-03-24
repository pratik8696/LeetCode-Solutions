int a,b,x,cc=0;
unordered_map<int,int> hsh;
int dp[6001][2];

int sum(int idx,int pre)
{
    if(idx==x)
    {
        return 0;
    }
    if(hsh[idx]>0||idx>6000||idx<0||pre>=2)
    {
        return 1e8;
    }
    auto &dimp=dp[idx][pre];
    if(dimp!=-1)
    {
        return dimp;
    }
    int ans=1e8;
    ans=min(ans,sum(idx+a,0)+1);
    dimp=ans;
    if(!pre&&idx-b>=0)
        ans=min(ans,sum(idx-b,1)+1);
    return dimp = ans;
}

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int aa, int bb, int xx) {
        hsh.clear();
        cc=0;
        for(auto t:forbidden)
        {
            hsh[t]++;
        }
        a=aa,b=bb,x=xx;
        memset(dp,-1,sizeof(dp));
        int val = sum(0,0);
        return (val>=1e8?-1:val);
    }
};