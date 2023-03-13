class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.length();
        int max_dig=-1,last_pos_max=0;
        int l=0,r=0;
        for(int i=n-1;i>=0;i--)
        {
            if(max_dig<s[i]-'0')
            {
                max_dig=s[i]-'0';
                last_pos_max=i;
            }
            if(max_dig>s[i]-'0')
            {
                l=i;
                r=last_pos_max;
            }
        }
        swap(s[r],s[l]);
        return stoi(s);
    }
};