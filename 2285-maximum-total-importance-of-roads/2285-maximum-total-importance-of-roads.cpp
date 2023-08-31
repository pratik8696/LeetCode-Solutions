typedef long long ll;
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int,int> in;
        for(auto t:roads)
        {
            int u=t[0],v=t[1];
            in[u]++,in[v]++;
        }
        vector<int> arr;
        for(auto t:in)
        {
            arr.push_back(t.second);
        }
        sort(begin(arr),end(arr));
        ll ans=0;
        for(int i=arr.size()-1;i>=0;i--)
        {
            ans+=ll(arr[i])*ll(n--);
        }
        return ans;
    }
};