class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int i=m-1,j=n-1,k=m+n-1;
        while(i>=0&&j>=0)
        {
            if(a[i]<b[j])
            {
                a[k]=b[j];
                k--,j--;
            }
            else
            {
                a[k]=a[i];
                k--,i--;
            }
        }
        while(j>=0)
        {
            a[k]=b[j];
            j--,k--;
        }
    }
};