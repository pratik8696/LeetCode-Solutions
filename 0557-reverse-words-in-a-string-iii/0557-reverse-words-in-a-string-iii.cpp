class Solution {
public:
    string reverseWords(string s) {
        s.push_back(' ');
        string temp="",ans="";
        for(auto t:s)
        {
            if(t==' ')
            {
                reverse(temp.begin(),temp.end());
                temp.push_back(' ');
                ans.append(temp);
                temp.clear();
            }
            else
            {
                temp.push_back(t);
            }
        }
        ans.pop_back();
        return ans;
    }
};