class DSU
{
    public HashMap<Integer,Integer> parent;
    public HashMap<Integer,Integer> size;
    DSU(int[] arr)
    {
        int n=arr.length;
        parent=new HashMap<>();
        size=new HashMap<>();
        for(int i=0;i<n;i++)
        {
            parent.put(arr[i],arr[i]);
            size.put(arr[i],1);
        }
    }
    public int find(int x)
    {
        if(x==parent.get(x)) return x;
        return parent.put(x,find(parent.get(x)));
    }
    public int sz(int x)
    {
        return size.get(find(x));
    }
    public void join(int a,int b)
    {
        a=find(a);
        b=find(b);
        if(a!=b)
        {
            if(size.get(a)<size.get(b))
            {
                int t=a;
                a=b;
                b=t;
            }
            int new_val=size.get(a)+size.get(b);
            size.put(a,new_val);
            parent.put(b,a);
        }
    }
    
};

class Solution {
    public int longestConsecutive(int[] nums) {
        int n=nums.length,ans=0;
        DSU d=new DSU(nums);
        HashMap<Integer,Integer> m=new HashMap<>();
        HashSet<Integer> s=new HashSet<>();
        for(int i=0;i<n;i++)
        {
            s.add(nums[i]);
        }
        int parent=-1;
        for(Integer t:s)
        {
            // System.out.println("Index value is "+nums[i]);
            // System.out.println("Parent HashMap");
            // d.parent.forEach((key,value)->{
            //     System.out.println("Key is "+key+" and Value is "+value);
            // });
            // System.out.println("Size HashMap");
            // d.size.forEach((key,value)->{
            //     System.out.println("Key is "+key+" and Value is "+value);
            // });
            // System.out.println("___________END___________");
            if(m.containsKey(t-1)==true)
            {
                d.join(t,t-1);
            }
            if(m.containsKey(t+1)==true)
            {
                d.join(t,t+1);
            }                
            ans=Math.max(ans,d.sz(t));
            m.put(t,m.getOrDefault(t,0)+1);
        }
        return ans;
    }
}