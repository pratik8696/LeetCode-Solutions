class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        int n=arr.size(),m=arr[0].size();
        int top=0,down=n-1,left=0,right=m-1,direction=1;
        vector<int> ans;
        while(top <= down && left <= right)
        {
            if(direction==1)
            {
                for(int x=left;x<=right;x++)
                {
                    ans.push_back(arr[top][x]);
                }
                top++;
                direction++;
                continue;
            }
            
            if(direction==2)
            {
                for(int x=top;x<=down;x++)
                {
                    ans.push_back(arr[x][right]);
                }
                right--;
                direction++;
                continue;
            }
            
            
            if(direction==3)
            {
                for(int x=right;x>=left;x--)
                {
                    ans.push_back(arr[down][x]);
                }
                down--;
                direction++;
                continue;
            }
            
            if(direction==4)
            {
                for(int x=down;x>=top;x--)
                {
                    ans.push_back(arr[x][left]);
                }
                left++;
                direction=1;
                continue;
            }
        }
        
        return ans;
    }
};