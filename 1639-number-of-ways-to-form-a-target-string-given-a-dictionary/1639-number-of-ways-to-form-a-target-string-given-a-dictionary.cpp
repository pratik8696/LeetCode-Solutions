typedef long long ll;
const int MOD=1e9+7;
ll dp[1001][1001];
ll sum(ll idx,ll rem,string &s,unordered_map<int,vector<int>> &arr)
{
    if(rem==s.length())
    {
        return 1;
    }
    if(idx==arr.size())
    {
        return 0;
    }
    auto &x=dp[idx][rem];
    if(x!=-1)
    {
        return x;
    }
    ll ans=0;
    ans+=sum(idx+1,rem,s,arr);
    ans+=sum(idx+1,rem+1,s,arr)*arr[idx][int(s[rem]-'a')];
    ans%=MOD;
    return x = ans;
}
class Solution {
public:
    int numWays(vector<string>& s, string r) {
        int n=s.size(),m=s[0].length();
        unordered_map<int,vector<int>> arr;
        for(int i=0;i<m;i++)
        {
            arr[i].resize(26);
        }
        for(int j=0;j<m;j++)
        {
            for(int i=0;i<n;i++)
            {
                arr[j][int(s[i][j]-'a')]++;
            }
        }
        memset(dp,-1,sizeof(dp));
        return sum(0,0,r,arr);
    }
};