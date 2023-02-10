int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool isvalid(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
    {
        return false;
    }
    return true;
}

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }
        int maxx=0;
        while (!q.empty())
        {
            int currx = q.front().first;
            int curry = q.front().second;
            maxx=max(maxx,dist[currx][curry]);
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int x1 = currx + dx[i];
                int y1 = curry + dy[i];
                if (isvalid(currx + dx[i], curry + dy[i])&&grid[x1][y1]==0)
                {
                    if(dist[x1][y1]>dist[currx][curry]+1)
                    {
                        dist[x1][y1] = dist[currx][curry] + 1;
                        q.push({x1, y1});
                    }
                }
            }
        }
        return (maxx==0?-1:maxx);
    }
};