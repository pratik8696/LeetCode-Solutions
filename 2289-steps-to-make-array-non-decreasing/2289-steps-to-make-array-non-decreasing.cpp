class Solution {
public:
    int totalSteps(vector<int>& arr) {
        int n=arr.size(),ans=0;
        vector<int> next(n);
        vector<int> dist(n);
        vector<int> vis(n);
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            next[i]=i+1;
        }
        for(int i=n-1;i>=1;i--)
        {
            if(arr[i-1]>arr[i])
            {
                q.push({i-1,i});
            }
        }
        while(q.size())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            if(j==n||vis[i])
            {
                continue;
            }
            if(arr[i]>arr[j]&&next[j]>j)
            {
                vis[j]=1;
                next[i]=next[j];
                dist[i]++;
                q.push({i,next[i]});
            }
        }
        return *max_element(begin(dist),end(dist));
    }
};