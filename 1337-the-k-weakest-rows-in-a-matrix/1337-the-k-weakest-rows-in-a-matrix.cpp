class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> arr;
        int idx=0;
        for(auto t:mat)
        {
            int cc=0;
            for(auto x:t)
            {
                cc+=x;
            }
            arr.push_back({cc,idx});
            idx++;
        }
        sort(begin(arr),end(arr));
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(arr[i].second);
        }
        return ans;
    }
};