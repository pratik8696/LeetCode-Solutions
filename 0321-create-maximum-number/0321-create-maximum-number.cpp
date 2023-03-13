vector<int> r(vector<int> &s, int k) {
    deque<int> st;
    int len=s.size()-k;
    for(auto t:s)
    {
        while(st.size()&&st.back()<t&&k)
        {
            k--;
            st.pop_back();
        }
        st.push_back(t);
    }
    while(k&&st.size())
    {
        st.pop_back();
        k--;
    }
    vector<int> ans;
    for(int i=0;i<min(len,(int)st.size());i++)
    {
        ans.push_back(st[i]);
    }
    if(ans.size()==0)
    {
        return {};
    }
    return ans;
}

vector<int> merge(vector<int> &a,vector<int> &b)
{
    vector<int> res;
    int i=0,j=0;
    int n=a.size(),m=b.size();
    while(i<n&&j<m)
    {
        if(a[i]>b[j])
        {
            res.push_back(a[i]);
            i++;
        }
        else if(a[i]<b[j])
        {
            res.push_back(b[j]);
            j++;
        }
        else if(a[i]==b[j])
        {
            int i1=i,j1=j;
            while(i1<n&&j1<m&&a[i1]==b[j1])
            {
                i1++,j1++;
            }
            if(i1==a.size())
            {
                res.push_back(b[j]);
                j++;
            }
            else if(j1==b.size())
            {
                res.push_back(a[i]);
                i++;
            }
            else if(a[i1]>b[j1])
            {
                res.push_back(a[i]);
                i++;
            }
            else if(a[i1]<b[j1])
            {
                res.push_back(b[j]);
                j++;
            }
        }
    }
    while(i<n)
    {
        res.push_back(a[i]);
        i++;
    }
    while(j<m)
    {
        res.push_back(b[j]);
        j++;
    }
    return res;
}

class Solution {
public:
    vector<int> maxNumber(vector<int>& a, vector<int>& b, int k) {
        int n=a.size(),m=b.size();
        vector<int> ans(k,0);
        for(int i=0;i<=k;i++)
        {
            vector<int> f=r(a,a.size()-i);  // a.size()-i
            vector<int> s=r(b,b.size()-(k-i)); // b.size()-(k-i);
            
            vector<int> v=merge(f,s);
            if(v.size()==k&&ans<v)
                ans=v;
        }
        return ans;
    }
};