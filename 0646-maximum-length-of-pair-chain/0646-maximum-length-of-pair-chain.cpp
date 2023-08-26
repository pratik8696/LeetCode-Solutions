class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        vector<pair<int,int>> arr;
        for(auto t:pairs)
        {
            arr.push_back({t[0],t[1]});
        }
        sort(begin(arr),end(arr));
        vector<int> val(n);
        for(int i=0;i<arr.size();i++)
        {
            int value=0;
            for(int j=i-1;j>=0;j--)
            {
                if(arr[i].first>arr[j].second)
                {
                    value=max(value,val[j]);
                }
            }
            val[i]=value+1;
        }
        return *max_element(begin(val),end(val));
    }
};