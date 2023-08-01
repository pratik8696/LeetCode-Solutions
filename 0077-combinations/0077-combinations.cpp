typedef long long ll;
vector<vector<int>> ans;

void f(int idx,int k,int n,vector<int> &curr)
{
    if(idx>n)
    {
        // yha pr return kro
        if(k==0)
        {
            ans.push_back(curr);
        }
        return;
    }
    f(idx+1,k,n,curr);
    if(k>0)
    {
        curr.push_back(idx);
        f(idx+1,k-1,n,curr);
        curr.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        ans.clear();
        vector<int> curr;
        f(1,k,n,curr);
        return ans;
    }
};