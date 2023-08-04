vector<string> arr = {
    "", "", "abc", "def", "ghi", "jkl",
    "mno", "pqrs", "tuv", "wxyz"
};

vector<string> ans;

void sum(int idx,string &curr,string &s)
{
    if(idx==s.length())
    {
        if(curr.length())
        {
            ans.push_back(curr);
        }
        return;
    }
    for(auto t:arr[s[idx]-'0'])
    {
        curr.push_back(t);
        sum(idx+1,curr,s);
        curr.pop_back();
    }
}

class Solution {
public:
    vector<string> letterCombinations(string s) {
        ans.clear();
        string curr="";
        sum(0,curr,s);
        return ans;
    }
};