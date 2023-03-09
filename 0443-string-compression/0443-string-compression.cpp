class Solution {
public:
    int compress(vector<char>& s) {
        vector<char> res;
        char prev=s[0];
        int cc=0;
        s.push_back('~');
        int ans=0;
        for(auto t:s)
        {
            if(prev!=t)
            {
                if(cc==1)
                {
                    ans++;
                    res.push_back(prev);
                }
                else
                {
                    ans++;
                    res.push_back(prev);
                    string num=to_string(cc);
                    ans+=num.length();
                    for(auto x:num)
                    {
                        res.push_back(x);
                    }
                }
                prev=t;
                cc=1;
            }
            else
            {
                cc++;
            }
        }
        s=res;
        return ans;
    }
};