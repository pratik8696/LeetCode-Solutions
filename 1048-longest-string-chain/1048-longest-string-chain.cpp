bool compare(string &a,string &b)
{
    if(a.length()==b.length())
    {
        return a<b;
    }
    return a.length()<b.length();
}
class Solution {
public:
    bool check(string &a,string &b)
    {
        int i=0,j=0,cc=0;
        while(i<a.length()&&j<b.length())
        {
            if(a[i]==b[j])
            {
                i++,j++;
            }
            else
            {
                j++;
                cc++;
            }
        }
        while(j<b.length())
        {
            cc++,j++;
        }
        return (i==a.length()&&cc==1);
    }
    
    int longestStrChain(vector<string>& words) 
    {
        int n=words.size();
        sort(begin(words),end(words),compare);
        // for(auto t:words)
        // {
        //     cout<<t<<" ";
        // }
        // cout<<endl;
        vector<int> pre(n);
        for(int i=0;i<n;i++)
        {
            int cc=0;
            for(int j=i-1;j>=0;j--)
            {
                if(check(words[j],words[i]))
                    cc=max(cc,pre[j]);
            }
            pre[i]=cc+1;
            // cout<<pre[i]<<" ";
        }
        // cout<<endl;
        return *max_element(begin(pre),end(pre));
    }
};