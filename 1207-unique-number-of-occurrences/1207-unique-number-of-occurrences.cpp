class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m,hsh;
        for(auto t:arr)
        {
            m[t]++;
        }
        for(auto t:m)
        {
            hsh[t.second]++;
        }
        for(auto t:hsh)
        {
            if(t.second>1)
            {
                return false;
            }
        }
        return true;
    }
};