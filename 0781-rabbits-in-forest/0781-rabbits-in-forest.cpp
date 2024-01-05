class Solution {
public:
    int ce(int x,int y)
    {
        int res=x/y;
        if(x%y)
        {
            res++;
        }
        return res;
    }
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> m;
        for(auto t:answers)
        {
            m[t+1]++;
        }
        int ans=0;
        for(auto t:m)
        {
            ans+=ce(t.second,t.first)*t.first;
        }
        return ans;
    }
};