class Solution {
public:
    vector<vector<int>> generateMatrix(int x) {
        int n=x,m=x;
        int top=0,down=n-1,left=0,right=m-1,direction=1,cc=1;
        vector<vector<int>> arr(n,vector<int>(n));
        while(top <= down && left <= right)
        {
            if(direction==1)
            {
                for(int x=left;x<=right;x++)
                {
                    arr[top][x]=cc++;
                }
                top++;
                direction++;
                continue;
            }
            
            if(direction==2)
            {
                for(int x=top;x<=down;x++)
                {
                    arr[x][right]=cc++;
                }
                right--;
                direction++;
                continue;
            }
            
            
            if(direction==3)
            {
                for(int x=right;x>=left;x--)
                {
                    arr[down][x]=cc++;
                }
                down--;
                direction++;
                continue;
            }
            
            if(direction==4)
            {
                for(int x=down;x>=top;x--)
                {
                    arr[x][left]=cc++;
                }
                left++;
                direction=1;
                continue;
            }
        }
        
        return arr;        
    }
};