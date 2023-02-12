vector<int> right(vector<int> &arr)
{
    int n=arr.size();
    vector<int> v,ans(n);
    for(int i=n-1;i>=0;i--)
    {
        while(v.size()&&arr[v.back()]>=arr[i])
        {
            v.pop_back();
        }
        if(v.size()==0)
        {
            ans[i]=n;
        }
        else
        {
            ans[i]=v.back();
        }
        v.push_back(i);
    }
    return ans;
}

vector<int> left(vector<int> &arr)
{
    int n=arr.size();
    vector<int> v,ans(n);
    for(int i=0;i<n;i++)
    {
        while(v.size()&&arr[v.back()]>=arr[i])
        {
            v.pop_back();
        }
        if(v.size()==0)
        {
            ans[i]=-1;
        }
        else
        {
            ans[i]=v.back();
        }
        v.push_back(i);
    }
    return ans;
}

class Solution {
public:
    int largestRectangleArea(vector<int>& arr)
    {
        int n=arr.size();
        vector<int> r=right(arr);
        vector<int> l=left(arr);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int diff=abs(r[i]-l[i]);
            diff--;
            ans=max(ans,diff*arr[i]);
        }
        return ans;
    }
};