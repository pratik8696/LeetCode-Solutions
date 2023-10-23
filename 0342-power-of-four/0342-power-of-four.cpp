class Solution {
public:
    bool isPowerOfFour(int n) {
        if( n==0)
        {
            return false;
        }
        double val=log2(n);
        if(floor(val)==ceil(val)&&(int)val%2==0)
        {
            return true;
        }
        return false;
    }
};