class Pair{
    int a,b;
    Pair(int a,int b)
    {
        this.a=a;
        this.b=b;
    }
};

class Solution {
    public int[] kWeakestRows(int[][] arr, int k) {
        int n=arr.length;
        int m=arr[0].length;
        Comparator<Pair> comp=new Comparator<Pair>()
        {
            public int compare(Pair a,Pair b)
            {
                return Integer.compare(a.a,b.a);
            }
        };
        ArrayList<Pair> a=new ArrayList<>();
        for(int i=0;i<n;i++)
        {
            int cc=0;
            for(int j=0;j<m;j++)
            {
                cc+=arr[i][j];
            }
            a.add(new Pair(cc,i));
        }
        Collections.sort(a,comp);
        int[] ans=new int[k];
        for(int i=0;i<k;i++)
        {
            ans[i]=a.get(i).b;
        }
        // for(Pair x:a)
        // {
        //     System.out.println(x.a+" "+x.b);
        // }
        return ans;
    }
}