class Solution {
public:
    string longestPalindrome(string s) {
        string res="";
        res.push_back(s.back());
        for(int i=0;i<s.length();i++)
        {
            int left=i-1,right=i+1,ans=1;
            while(left>=0&&right<s.length()&&s[left]==s[right])
            {
                left--;
                right++;
                ans+=2;
            }
            if(res.length()<ans)
            {
                res=s.substr(left+1,ans);
            }
            if(i+1<s.length())
            {
                if(s[i]==s[i+1])
                {
                    left=i-1,right=i+2;
                    ans=2;
                    while(left>=0&&right<s.length()&&s[left]==s[right])
                    {
                        left--;
                        right++;
                        ans+=2;
                    }
                    if(res.length()<ans)
                    {
                        res=s.substr(left+1,ans);
                    }
                }
            }
        }
        return res;
    }
};