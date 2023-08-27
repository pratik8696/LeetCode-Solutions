int dp[2001][2001];
bool sum(int idx,int k,vector<int> &arr,unordered_map<int,int> &hsh)
{
    if(idx==arr.size()-1)
    {
        return true;
    }
    auto &x=dp[idx][k];
    if(x!=-1)
    {
        return x;
    }
    bool ans=false;
    if(hsh[arr[idx]+k] && k>0)
    {
        ans|=sum(hsh[arr[idx]+k],k,arr,hsh);
    }
    if(hsh[arr[idx]+k+1])
    {
        ans|=sum(hsh[arr[idx]+k+1],k+1,arr,hsh);
    }
    if(hsh[arr[idx]+k-1] && k-1>0)
    {
        ans|=sum(hsh[arr[idx]+k-1],k-1,arr,hsh);
    }    
    return x=ans;
}

class Solution {
public:
    bool canCross(vector<int>& arr) 
    {
        unordered_map<int,int> hsh;
        for(int i=0;i<arr.size();i++)
        {
            hsh[arr[i]]=i;
        }
        memset(dp,-1,sizeof(dp));
        return sum(0,0,arr,hsh);
    }
};