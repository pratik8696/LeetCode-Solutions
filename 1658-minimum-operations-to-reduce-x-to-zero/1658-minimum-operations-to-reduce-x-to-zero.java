class Solution {
    public int minOperations(int[] nums, int x) {
        int n=nums.length,total=0;
        for(int xxx:nums) total+=xxx;
        if(total<x) return -1;
        int i=0,sum=0,k=total-x,ans=-1;
        for(int j=0;j<n;j++)
        {
            sum+=nums[j];
            while(sum>k)
                sum-=nums[i++];
            if(sum==k)
                ans=Math.max(ans,j-i+1);
        }
        if(ans==-1) return -1;
        return n-ans;
    }
}