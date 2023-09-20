class Solution {
    public int findNumberOfLIS(int[] nums) {
        int n=nums.length;
        int[] dp=new int[n+1];
        int[] count=new int[n+1];
        for(int i=0;i<n;i++)
        {
            int max_count=0,value=0;
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]>nums[j])
                {
                    if(value<dp[j])
                    {
                        value=dp[j];
                        max_count=count[j];
                    }
                    else if(value==dp[j])
                    {
                        max_count+=count[j];
                    }
                }
            }
            dp[i]=value+1;
            count[i]=Math.max(max_count,1);
        }
        for(int i=0;i<n;i++)
        {
            // System.out.print(dp[i]+" ");
        }
        // System.out.println(" ");
        int maxx=0,ans=0;
        for(int i=0;i<n;i++)
        {
            // System.out.print(count[i]+" ");
            maxx=Math.max(dp[i],maxx);
        }
        for(int i=0;i<n;i++)
        {
            if(maxx==dp[i])
            {
                ans+=count[i];
            }
        }
        // System.out.println(" ");
        return ans;
    }
}