class Solution {
public:
    int longestSubarray(vector<int>& arr, int limit) {
        int n=arr.size(),j=0,ans=0;
        multiset<int> s;
        for(int i=0;i<n;i++)
        {
            s.insert(arr[i]);
            while(*s.rbegin()-*s.begin()>limit)
            {
                s.erase(s.find(arr[j++]));
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};