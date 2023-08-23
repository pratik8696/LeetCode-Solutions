bool compare(pair<char,int> &a,pair<char,int> &b)
{
    return a.second>b.second;
}

class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> m;
        for(auto t:s)
        {
            m[t]++;
            if(m[t]>(s.length()+1)/2)
            {
                return "";
            }
        }
        vector<pair<char,int>> dq;
        for(auto t:m)
        {
            dq.push_back({t.first,t.second});
        }
        sort(begin(dq),end(dq),compare);
        int flag=0;
        string ans(s.length(),'.');
        s.clear();
        s="";
        for(auto t:dq)
        {
            int val=t.second;
            while(val--)
            {
                s.push_back(t.first);
            }
        }
        int i=0;
        for(int j=0;j<ans.length();j+=2)
        {
            ans[j]=s[i++];
        }
        for(int j=1;j<ans.length();j+=2)
        {
            ans[j]=s[i++];
        }
        cout<<ans<<endl;
        return ans;
    }
};