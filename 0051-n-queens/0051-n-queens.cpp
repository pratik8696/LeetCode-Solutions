bool isvalid(int x,int y,int n)
{
    if(x>=0&&x<n&&y>=0&&y<n)
    {
        return true;
    }
    return false;
}

bool issafe(int x,int y,vector<string> &arr)
{
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        if(arr[x][i]=='Q'||arr[i][y]=='Q')
        {
            return false;
        }
    }
    int i=x,j=y;
    while(isvalid(i,j,n))
    {
        if(arr[i][j]=='Q')
        {
            return false;
        }
        i++,j++;
    }
    i=x,j=y;
    while(isvalid(i,j,n))
    {
        if(arr[i][j]=='Q')
        {
            return false;
        }
        i--,j--;
    }    
    i=x,j=y;
    while(isvalid(i,j,n))
    {
        if(arr[i][j]=='Q')
        {
            return false;
        }
        i++,j--;
    }    
    i=x,j=y;
    while(isvalid(i,j,n))
    {
        if(arr[i][j]=='Q')
        {
            return false;
        }
        i--,j++;
    }  
    return true;
}

vector<vector<string>> ans;

void sum(int row,int col,int cc,vector<string> &arr)
{
    int n=arr.size();
    
    if(row == n)
    {
        if(cc==n)
            ans.push_back(arr);
        
        return;
    }
    
    for(int i=0;i<n;i++)
    {
        if(issafe(row,i,arr))
        {
            arr[row][i]='Q';
            sum(row+1,0,cc+1,arr);
            arr[row][i]='.';
        }
    }
}

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> arr;
        for(int i=0;i<n;i++)
        {
            string s(n,'.');
            arr.push_back(s);
        }
        ans.clear();
        sum(0,0,0,arr);
        return ans;
    }
};