int dp[1001][4][2][1002];
int sum(int idx,int rem,int type,int prev_idx,vector<int> &arr)
{
    int n=arr.size();
    if(rem==0)
    {
        return 1;
    }
    if(idx==n)
    {
        return 0;
    }
    auto &x=dp[idx][rem][type][prev_idx+1];
    if(x!=-1)
    {
        return x;
    }
    int ans=0;
    ans+=sum(idx+1,rem,type,prev_idx,arr);
    if(type==0)
    {
        if(prev_idx==-1||arr[prev_idx]<arr[idx])
        {
            ans+=sum(idx+1,rem-1,type,idx,arr);
        }
    }
    else
    {
        if(prev_idx==-1||arr[prev_idx]>arr[idx])
        {                     
            ans+=sum(idx+1,rem-1,type,idx,arr);
        }        
    }
    return x = ans;
}

class Solution {
public:
    int numTeams(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        int a=0,b=0;
        a=sum(0,3,0,-1,arr);
        b=sum(0,3,1,-1,arr);
        cout<<a<<" "<<b<<endl;
        return a+b;
    }
};