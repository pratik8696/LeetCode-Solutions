int dp[int(1e4+1)];
int sum(int idx,vector<pair<int,int>> &arr)
{
    if(idx==arr.size())
    {
        return 1e9;
    }
    // cout<<idx<<endl;
    if(arr[idx].second==arr.size()-1)
    {
        return 0;
    }
    auto &x=dp[idx];
    if(x!=-1)
    {
        return x;
    }
    int ans=1e9;
    for(int i=idx+1;i<arr.size();i++)
    {
        if(arr[idx].second>=arr[i].first)
            ans=min(ans,sum(i,arr)+1);
    }
    return x=ans;
}


class Solution {
public:
    int minTaps(int x, vector<int>& arr) {
        int n=arr.size();
        vector<pair<int,int>> res;
        int ans=1e9;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            int left=i-arr[i];
            int right=i+arr[i];
            res.push_back({max(0,left),min(right,x)});
        }
        for(int i=0;i<n;i++)
        {
            int left=i-arr[i];
            if(left<=0)
            {
                ans=min(ans,sum(i,res)+1);
            }        
        }        
        return (ans==1e9?-1:ans);
    }
};