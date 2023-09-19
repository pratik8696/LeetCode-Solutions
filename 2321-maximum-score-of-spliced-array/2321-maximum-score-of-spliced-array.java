class Solution {
    public int kadane(int[] a,int[] b)
    {
        int curr=-100,maxx=0;
        for(int i=0;i<a.length;i++)
        {
            int x=a[i]-b[i];
            System.out.print(x+" , ");
            curr=Math.max(curr+x,x);
            maxx=Math.max(maxx,curr);
        }
        // System.out.println(" ");
        // System.out.println("KADANE'S -> "+maxx);
        return maxx;
    }
    
    public int maximumsSplicedArray(int[] a, int[] b) {
        int n=a.length;
        int sum1=0,sum2=0;
        for(int i:a) sum1+=i;
        for(int i:b) sum2+=i;
        // System.out.println(sum1+" "+sum2);
        // System.out.println(kadane(a,b));
        // System.out.println(kadane(b,a));
        // return 0;
        return Math.max(sum1+kadane(b,a),sum2+kadane(a,b));
    }
}