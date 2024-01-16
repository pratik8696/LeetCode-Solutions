typedef long long ll;
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& arr) {
        int n=arr.size();
        unordered_map<ll,ll> lose;
        set<int> s;
        for(int i=0;i<n;i++)
        {
            lose[arr[i][1]]++;
            s.insert(arr[i][0]);
            s.insert(arr[i][1]);
        }
        vector<int> a,b;
        for(auto t:s)
        {
            if(lose[t]==0)
            {
                a.push_back(t);
            }
            else if(lose[t]==1)
            {
                b.push_back(t);
            }
        }        
        vector<vector<int>> v;
        v.push_back(a);
        v.push_back(b);
        return v;
    }
};