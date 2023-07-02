class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m=requests.size(),ans=0;
        for(int mask=0;mask<(1<<m);mask++)
        {
            vector<int> in(n),out(n);
            for(int i=0;i<m;i++)
            {
                int val=mask&(1<<i);
                if(val)
                {
                    int u=requests[i][0];
                    int v=requests[i][1];
                    in[v]++;
                    out[u]++;
                }
            }
            int flag=1;
            for(int i=0;i<n;i++)
            {
                if(in[i]!=out[i])
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                ans=max(ans,__builtin_popcount(mask));
            }
        }
        return ans;
    }
};