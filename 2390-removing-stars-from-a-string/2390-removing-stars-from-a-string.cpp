class Solution {
public:
    string removeStars(string s) {
        string ans="";
        for(auto t:s)
        {
            if(t=='*')
            {
                ans.pop_back();
            }
            else
            {
                ans.push_back(t);
            }
        }
        return ans;
    }
};