class Solution {
public:
    int ans=0;
    void f(int n,int index,int reverse)
    {
        if(n==1)
        {
            ans=reverse;
            return;
        }
        int mid=n/2;
        if(index>mid)
        {
            f(n/2,index-(n/2),(reverse+1)%2);
        }
        else
        {
            f(n/2,index,reverse);
        }
    }
    
    int kthGrammar(int n, int k) {
        f(1<<(n-1),k,0);
        return ans;
        /* 
            1-0
            2-01
            3-0110
            4-01101001
            5-0110100110010110
            16 letters hai usme se 3rd btao
            n ho gya 4 and length is now 8
            n ho gya 3 and length is now 4 (position is now 2)
            n ho gya 2 and length is now 2 (reverse)
            n ho gya 1 and length is now 1 (reverse)
            1st row mai 1st symbol
            2nd row mai 1st symbol
        */
    }
};