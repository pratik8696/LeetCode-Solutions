class Solution {
public:
    int countOdds(int l, int r) {
        if(l%2!=r%2)
        {
            return (r-l+1)/2;
        }
        else if(l%2)
        {
            return (r-l+2)/2;
        }
        else
        {
            return (r-l)/2;
        }
    }
};