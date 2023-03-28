typedef long long ll;

ll n;
ll dp[400][400];
ll sum(vector<int> arr, ll i, ll valid, vector<int> cost)
{
    if (i == 0)
    {
        return 0;
    }
    if (dp[i][valid] != -1)
    {
        return dp[i][valid];
    }
    ll ans = 1e10;
    if (arr[i - 1] > valid)
    {
        ans = min({ans, sum(arr, i - 1, arr[i - 1] + 1 - 1, cost) + cost[0],
                   sum(arr, i - 1, arr[i - 1] + 7 - 1, cost) + cost[1],
                   sum(arr, i - 1, arr[i - 1] + 30 - 1, cost) + cost[2]});
    }
    else
    {
        // else buy and don't buy
        ans = min({ans, sum(arr, i - 1, arr[i - 1] + 1 - 1, cost) + cost[0],
                   sum(arr, i - 1, arr[i - 1] + 7 - 1, cost) + cost[1],
                   sum(arr, i - 1, arr[i - 1] + 30 - 1, cost) + cost[2],
                   sum(arr, i - 1, valid, cost)});
    }
    return dp[i][valid] = ans;
}


class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        n=days.size();
        reverse(days.begin(),days.end());
        return sum(days,n,0,costs);
    }
};