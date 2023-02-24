vector<vector<int>> res;
void sum(int idx,int rem,vector<pair<int,int>> &v,vector<int> &ans)
{
    if(idx==v.size())
    {
        if(rem==0)
        {
            res.push_back(ans);
        }
        return;
    }
    
    // take it 
    int cc=0;
    for(int i=1;i<=v[idx].second;i++)
    {
        if(rem>=i*v[idx].first)
        {
            cc=i;
            ans.push_back(v[idx].first);
            sum(idx+1,rem-(i*v[idx].first),v,ans);   
        }
    }
    while(cc--)
    {
        ans.pop_back();
    }
    sum(idx+1,rem,v,ans);
}

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        map<int,int> m;
        for(auto t:candidates)
        {
            m[t]++;
        }
        vector<pair<int,int>> v;
        for(auto t:m)
        {
            v.push_back({t.first,t.second});
        }
        vector<int> ans;
        res.clear();
        sum(0,target,v,ans);
        return res;
    }
};