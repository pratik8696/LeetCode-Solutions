class Solution {
    public int shortestSubarray(int[] nums, int k) {
        ArrayDeque<Integer> dq=new ArrayDeque<>();
        int n=nums.length,ans=Integer.MAX_VALUE;
        int res=n+1;
        long[] pre=new long[res];
        for(int i=1;i<n+1;i++)
        {
            pre[i]+=nums[i-1]+pre[i-1];
        }
        for(int i=0;i<pre.length;i++)
        {
            while(dq.size()>0&&pre[i]-pre[dq.getFirst()]>=k)
            {
                ans=Math.min(ans,i-dq.peekFirst());
                dq.pollFirst();
            }
            while(dq.size()>0&&pre[i]<=pre[dq.getLast()])
            {
                dq.pollLast();
            }
            dq.addLast(i);
        }
        return (ans==Integer.MAX_VALUE?-1:ans);
    }
}