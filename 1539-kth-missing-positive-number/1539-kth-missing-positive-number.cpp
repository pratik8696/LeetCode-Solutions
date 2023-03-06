class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        set<int> s;
        for(int i=1;i<=2000;i++)
        {
            s.insert(i);
        }
        for(auto t:arr)
        {
            s.erase(t);
        }
        k--;
        while(k--)
        {
            s.erase(s.begin());
        }
        return *s.begin();
    }
};