set<vector<int>> ans;
void sum(int idx,vector<int> &arr,vector<int> &a)
{
    if(idx==arr.size())
    {
        if(a.size()>1)
            ans.insert(a);
        return;
    }
    sum(idx+1,arr,a);
    if(a.size())
    {
        if(arr[idx]>=a.back())
        {
            a.push_back(arr[idx]);
            sum(idx+1,arr,a);
            a.pop_back();
        }
    }
    else
    {
        a.push_back(arr[idx]);
        sum(idx+1,arr,a);
        a.pop_back();
    }
    
}

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        ans.clear();
        vector<int> a;
        sum(0,nums,a);
        vector<vector<int>> res;
        for(auto t:ans)
        {
            res.push_back(t);
        }
        return res;
    }
};