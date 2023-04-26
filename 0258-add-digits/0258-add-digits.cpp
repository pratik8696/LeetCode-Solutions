class Solution {
public:
    int addDigits(int num) {
        int curr=num;
        while(curr>9)
        {
            int sum=0;
            while(curr)
            {
                sum+=curr%10;
                curr/=10;
            }
            curr=sum;
        }
        return curr;
    }
};