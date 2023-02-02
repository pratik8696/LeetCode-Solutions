typedef long long ll;
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        ll n=nums.size();
        ll i=0;
        ll sum=0,cc=0,ans=0;
        for(int j=0;j<n;j++)
        {
            sum+=nums[j];
            cc++;
            while(cc*nums[j]-sum>k)
            {
                cc--;
                sum-=nums[i++];
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};