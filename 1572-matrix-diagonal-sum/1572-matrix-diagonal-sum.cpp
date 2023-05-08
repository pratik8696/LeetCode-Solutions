class Solution {
public:
    int diagonalSum(vector<vector<int>>& arr) {
        int n=arr.size(),sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i][i]+arr[i][n-1-i];
        }
        return sum-(n%2==1?arr[n/2][n/2]:0);
    }
};