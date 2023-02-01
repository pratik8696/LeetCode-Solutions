int prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    if(n%(n-pi.back())==0)
    {
        // tb shi h
        return n-pi.back();
    }
    return -1;
}

class Solution {
public:
    string gcdOfStrings(string s, string r) {
        int n=s.length(),m=r.length();
        if(n<m)
        {
            swap(n,m);
            swap(s,r);
        }
        string curr="";
        int x=0;
        while(curr.length()<n)
        {
            curr.push_back(r[x%m]);
            x++;
        }
        r=curr;
        cout<<s<<" "<<r<<endl;
        if(s!=r)
        {
            return "";
        }
        int val1=prefix_function(s);
        if(val1==-1)
        {
            return "";   
        }
        int ans=0;
        for(int i=1;i<1001;i++)
        {
            int cur=i*val1;
            if(n%cur==0&&m%cur==0)
            {
                ans=max(ans,cur);
            }
        }
        return s.substr(0,ans);
    }
};