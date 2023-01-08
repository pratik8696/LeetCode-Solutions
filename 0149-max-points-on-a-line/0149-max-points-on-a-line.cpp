class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size(),ans=0;
        map<int,int> xx,yy;
        for(int i=0;i<n;i++)
        {
            xx[points[i][0]]++;
            yy[points[i][1]]++;
            ans=max(ans,xx[points[i][0]]);
            ans=max(ans,yy[points[i][1]]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                int x1=points[i][0],y1=points[i][1];
                int x2=points[j][0],y2=points[j][1];
                int num=y2-y1;
                int denom=x2-x1;
                int cc=0;
                for(int k=0;k<n;k++)
                {
                    int x=points[k][0],y=points[k][1];
                    int xdiff=x-x1;
                    int ydiff=y1-y;
                    int prod=num*xdiff;
                    if(denom&&prod%denom==0)
                    {
                        int res=prod/denom;
                        if(res+ydiff==0)
                        {
                            cc++;
                        }
                    }
                }
                ans=max(ans,cc);
            }
        }
        return ans;
    }
};
