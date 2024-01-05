class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> m;
        for(auto t:answers)
        {
            m[t+1]++;
        }
        int ans=0;
        for(auto t:m)
        {
            ans += (t.second % t.first > 0 ? t.second / t.first + 1: t.second / t.first) * t.first;
        }
        return ans;
    }
};