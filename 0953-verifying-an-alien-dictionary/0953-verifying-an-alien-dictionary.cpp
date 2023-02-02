map<char,char> m;

bool comp(string &a,string &b)
{
    string x="",y="";
    for(auto t:a)
    {
        x.push_back(m[t]);
    }
    for(auto t:b)
    {
        y.push_back(m[t]);
    }    
    return x<y;
}

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<string> s=words;
        m.clear();
        for(int i=0;i<=25;i++)
        {
            m[order[i]]=char(i+'a');
        }
        sort(begin(s),end(s),comp);
        return s==words;
    }
};