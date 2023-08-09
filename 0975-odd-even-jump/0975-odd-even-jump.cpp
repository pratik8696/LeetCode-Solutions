int dp[int(2e4+1)][2];
bool dfs(int idx,int val,vector<int> &e,vector<int> &o)
{
    // cout<<"curr idx is "<<idx<<endl;
    if(idx==e.size()-1)
    {
        return true;
    }
    auto &x=dp[idx][val];
    if(x!=-1)
    {
        return x;
    }
    x=0;
    // cout<<e[idx]<<" "<<o[idx]<<endl;
    if(val&&o[idx]!=-1)
    {
        x|=dfs(o[idx],1-val,e,o);
    }
    if(e[idx]!=-1&&val==0)
    {
        x|=dfs(e[idx],1-val,e,o);
    }
    return x;
}

class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n=arr.size();
        map<int,int> even,odd;
        vector<int> e(n),o(n);
        for(int i=n-1;i>=0;i--)
        {
            auto it=even.lower_bound(arr[i]);
            if(it!=even.end())
            {
                e[i]=(*it).second;
            }
            else
            {
                e[i]=-1;
            }
            even[arr[i]]=i;
        }
        for(int i=n-1;i>=0;i--)
        {
            auto it=odd.upper_bound(arr[i]);
            if(it!=odd.begin())
            {
                it--;
                o[i]=(*it).second;
            }
            else
            {
                o[i]=-1;
            }
            odd[arr[i]]=i;
        }     
        swap(e,o);
        // for(auto t:e)
        // {
        //     cout<<t<<" ";
        // }
        // cout<<endl;
        // for(auto t:o)
        // {
        //     cout<<t<<" ";
        // }
        // cout<<endl;        
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            ans+=dfs(i,1,e,o);
        }
        // cout<<dfs(0,1,e,o)<<endl;
        return ans;
    }
};