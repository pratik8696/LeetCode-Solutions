class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq,ff;
        for(auto t:arr)
        {
            freq[t]++;
        }
        for(auto t:freq)
        {
            ff[t.second]++;
            if(ff[t.second]>1)
            {
                return false;
            }
        }
        return true;
    }
};