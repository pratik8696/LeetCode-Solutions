typedef long long ll;

class Solution {
public:
     bool f(ll m,vector<int>& nums , int p)
     {
         int c=0;
         for(int i=0;i<nums.size()-1;i++)
         {
              if(nums[i+1]-nums[i]<=m)
              {
                  c++;
                  i++;
              }
         }
         return c>=p;
     }
    int minimizeMax(vector<int>& nums, int p) {
     ll l =0,h=1e18 ,ans=0;
        sort(begin(nums),end(nums));
        while(l<=h)
        {
            ll m = (l+h)/2;
            if(f(m,nums,p))
            {
                ans = m;
                h = m-1;     
            }
            else
                l= m+1;
        }
        return ans;
    }
};