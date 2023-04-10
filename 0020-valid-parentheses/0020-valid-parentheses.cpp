class Solution {
public:
    unordered_map<char,int> m{{'(',1},{')',-1},{'{',2},{'}',-2},{'[',3},{']',-3}};
    bool isValid(string s) {
        stack<char> st;
        for(auto t:s)
        {
            if(m[t] > 0)
            {
                st.push(t);
            }
            else
            {
                if(!st.empty())
                {
                    if(m[t]+m[st.top()]==0)
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        if(!st.empty())
        {
            return false;
        }
        return true;
    }
};