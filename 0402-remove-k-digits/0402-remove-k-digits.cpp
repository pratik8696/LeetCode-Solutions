class Solution {
public:
    string removeKdigits(string s, int k) {
        deque<char> st;
        int len=s.length()-k;
        if(len==0)
        {
            return "0";
        }
        for(auto t:s)
        {
            while(st.size()&&int(st.back()-'0')>int(t-'0')&&k)
            {
                k--;
                st.pop_back();
            }
            st.push_back(t);
        }
        while(st.front()=='0')
        {
            st.pop_front();
        }
        while(k&&st.size())
        {
            st.pop_back();
            k--;
        }
        string ans="";
        for(int i=0;i<min(len,(int)st.size());i++)
        {
            ans.push_back(st[i]);
        }
        if(ans.size()==0)
        {
            return "0";
        }
        return ans;
    }
};