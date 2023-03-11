class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        while(i<s.length() && j<t.length())
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if(j!=t.length())
        {
            return false;
        }
        bool flag=true;
        while(i<s.length())
        {
            if(isupper(s[i]))
            {
                flag=false;
            }
            i++;
        }
        return flag;
    }
    
    vector<bool> camelMatch(vector<string>& q, string p) {
        int cnt2=0;
        for(int i=0;i<p.size();i++){
            if(isupper(p[i])){
                cnt2++;
            }
        }
        vector<bool> ans;
        for(int i=0;i<q.size();i++){
            string s=q[i];
            int n=s.size();
            int cnt1=0;
            for(int j=0;j<n;j++){
                if(isupper(s[j])){
                    cnt1++;
                }
            }
            if(cnt1==cnt2)
            {
                ans.push_back(isSubsequence(s,p));
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};