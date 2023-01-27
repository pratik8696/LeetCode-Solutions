#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

bool check(int idx,string &s,int count,unordered_set<string> &hsh)
{
    if(idx==s.length())
    {
        return count>=2;
    }
    string temp="";
    for(int i=idx;i<s.length();i++)
    {
        temp.push_back(s[i]);
        if(hsh.count(temp))
        {
            if(check(i+1,s,count+1,hsh))
            {
                return true;
            }
        }
    }
    return false;
}

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        fast_cin();
        unordered_set<string> hsh;
        for(auto t:words)
        {
            hsh.insert(t);
        }
        vector<string> ans;
        for(auto t:words)
        {
            if(check(0,t,0,hsh))
            {
                ans.push_back(t);
            }
        }
        return ans;
    }
};