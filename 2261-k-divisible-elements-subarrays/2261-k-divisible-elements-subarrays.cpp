class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n=nums.size();
        set<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            int cc=0;
            vector<int> curr;
            for(int j=i;j<n;j++)
            {
                curr.push_back(nums[j]);
                cc+=(nums[j]%p==0?1:0);
                if(cc<=k)
                {
                    ans.insert(curr);
                }
                else
                {
                    break;
                }
            }
        }
        return ans.size();
    }
};