class Solution {
public:
    int minCost(string s, vector<int>& v) {
        char prev=s[0];
        int curr=-1e9;
        s.push_back('?');
        v.push_back(0);
        int ans=0,res=0;
        for(int i=0;i<s.length();i++)
        {
            if(prev!=s[i])
            {
                res+=curr;
                prev=s[i];
                curr=v[i];
            }
            else
            {
                curr=max(curr,v[i]);    
            }
            ans+=v[i];
        }
        return ans-res;
    }
};