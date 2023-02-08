class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n);
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            pre[i]+=pre[i-1]+nums[i];
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            int prev=0,fwd=0;
            if(i-1>=0)
            {
                prev=abs(pre[i-1]-(i)*nums[i]);
            }
            fwd=abs((n-i-1)*nums[i]-(pre.back()-pre[i]));
            // cout<<prev<<" "<<fwd<<endl;
            ans.push_back(prev+fwd);
        }
        return ans;
    }
};