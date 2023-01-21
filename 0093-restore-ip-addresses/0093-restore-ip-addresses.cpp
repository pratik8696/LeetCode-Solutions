vector<string> res;
void create(int idx,string &s,vector<string> &ans)
{
    if(idx==s.length())
    {
        string curr="";
        if(ans.size()==4)
        {
            for(auto t:ans)   
            {
                curr+=t;
                curr+=".";
            }
            curr.pop_back();
            res.push_back(curr);
        }
        return;
    }
    // now we will include it and check whether it is valid;
    if(ans.size()>=4)
    {
        return;
    }
    if(s[idx]=='0')
    {
        ans.push_back("0");
        create(idx+1,s,ans);
        ans.pop_back();
    }
    else
    {
        string temp="";
        int sum=0;
        for(int i=idx;i<min(idx+4,(int)s.length());i++)
        {
            temp.push_back(s[i]);
            sum=sum*10+(s[i]-'0');
            if(sum<=255)
            {
                ans.push_back(temp);
                create(i+1,s,ans);
                ans.pop_back();
            }
        }
    }
}

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        vector<string> x;
        create(0,s,x);
        return res;
    }
};