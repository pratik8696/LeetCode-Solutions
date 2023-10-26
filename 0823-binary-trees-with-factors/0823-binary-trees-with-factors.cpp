typedef long long ll;
const int MOD = 1e9+7;
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<ll,ll> dp;
        ll res=0;
        for(int i=0;i<arr.size();i++)
        {
            dp[arr[i]]=1;
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0)
                {
                    dp[arr[i]]+=dp[arr[j]]*dp[arr[i]/arr[j]];
                    dp[arr[i]]%=MOD;
                }
            }
            res+=dp[arr[i]];
            res%=MOD;
        }
        return res;
    }
};