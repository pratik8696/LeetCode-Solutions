class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n=pref.size();
        vector<int> res;
        res.push_back(pref[0]);
        for(int i=1;i<n;i++)
        {
            int val=pref[i]^pref[i-1];
            res.push_back(val);
        }
        return res;
    }
};