class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<pair<int,int>> res;
        map<int,int> m;
        for(auto t:arr)
        {
            m[t]++;
        }
        for(auto t:m)
        {
            res.push_back({t.second,t.first});
        }
        sort(begin(res),end(res));
        int cc=0,k=0;
        while(res.size()&&2*k<arr.size())
        {
            k+=res.back().first;
            res.pop_back();
            cc++;
        }
        return cc;
    }
};