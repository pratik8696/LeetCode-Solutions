typedef long long ll;
ll dp[int(1e5+1)];
class Solution {
public:
    ll f(int idx,vector<pair<pair<int,int>,int>>&arr,vector<int> &a){

        if(idx>=arr.size())return 0;
        auto &x=dp[idx];
        if(x!=-1)
            return x;
        ll ans=0;    
        ans=max(ans,f(idx+1,arr,a));
        int next_idx=upper_bound(a.begin(),a.end(),arr[idx].first.second)-a.begin();
        ans=max(ans,f(next_idx,arr,a)+arr[idx].second);
        return x=ans;
    }

    int maximizeTheProfit(int n, vector<vector<int>>& a) {
        vector<pair<pair<int,int>,int>> arr;
        for(auto t:a){
            arr.push_back({{t[0],t[1]},t[2]});
        }
        sort(arr.begin(),arr.end());
        vector<int> array;
        for(auto t:arr){
            array.push_back(t.first.first);
        }
        memset(dp,-1,sizeof(dp));
        return f(0,arr,array);
    }
        

};