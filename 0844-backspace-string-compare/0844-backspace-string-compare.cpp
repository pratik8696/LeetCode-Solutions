class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> st,pt;
        for(auto t:s)
        {
            if(t=='#')
            {
                if(st.size())
                st.pop_back();
            }
            else
            {
                st.push_back(t);
            }
        }
        for(auto x:t)
        {
            if(x=='#')
            {
                if(pt.size())
                pt.pop_back();
            }
            else
            {
                pt.push_back(x);
            }
        }
        return st==pt;
    }
};