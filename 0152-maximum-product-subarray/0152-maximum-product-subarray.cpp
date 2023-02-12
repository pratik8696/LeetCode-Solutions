class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int maxx=arr[0],mini=arr[0],ans=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            auto t=arr[i];
            if(arr[i]<0)
            {
                swap(maxx,mini);
            }
            maxx=max(maxx*t,t);
            mini=min(mini*t,t);
            ans=max({maxx,mini,ans});
        }
        return ans;
    }
};