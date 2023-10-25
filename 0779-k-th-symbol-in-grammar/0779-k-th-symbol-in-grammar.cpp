class Solution {
public:
    int ans=0;
    void f(int n,int index,int reverse)
    {
        if(n==1){ans=reverse;return;}
        (index>n/2?f(n/2,index-(n/2),(reverse+1)%2):f(n/2,index,reverse));
    }
    
    int kthGrammar(int n, int k) {
        f(1<<(n-1),k,0);
        return ans;
    }
};