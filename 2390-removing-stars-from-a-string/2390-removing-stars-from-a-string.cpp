class Solution {
public:
    string removeStars(string s) {
        string ans="";
        int cc=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]=='*')
            {
                cc++;
            }
            else
            {
                if(cc==0)
                {
                    ans.push_back(s[i]);
                }
                else
                {
                    cc--;
                    continue;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};