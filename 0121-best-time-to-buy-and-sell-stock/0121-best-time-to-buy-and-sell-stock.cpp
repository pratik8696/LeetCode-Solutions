class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=INT_MAX,maxx=0;
        for(int i=0;i<n;i++)
        {
            mini=min(mini,prices[i]);
            maxx=max(maxx,prices[i]-mini);
        }
        return maxx;
    }
};