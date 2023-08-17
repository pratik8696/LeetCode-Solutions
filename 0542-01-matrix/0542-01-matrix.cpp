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

vector<vector<int>> bfson2d(vector<vector<int>> &arr)
{
    queue<pair<int, int>> q;
    n=arr.size(),m=arr[0].size();
    vector<vector<int>> dist(n,vector<int>(m,1e9));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==0)
            {
                q.push({i,j});
                dist[i][j]=0;
            }
        }
    }
    while (!q.empty())
    {
        int currx = q.front().first;
        int curry = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (isvalid(currx + dx[i], curry + dy[i]))
            {
                int x1 = currx + dx[i];
                int y1 = curry + dy[i];
                if(dist[x1][y1]>dist[currx][curry]+1)
                {
                    dist[x1][y1] = dist[currx][curry] + 1;
                    q.push({x1, y1});
                }
            }
        }
    }
    return dist;
}

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        return bfson2d(mat);
    }
};