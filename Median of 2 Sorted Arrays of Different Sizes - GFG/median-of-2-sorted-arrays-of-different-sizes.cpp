//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

bool check(int val,vector<int> &a,vector<int> &b,int res)
{
    int idx1=upper_bound(begin(a),end(a),val)-begin(a);
    int idx2=upper_bound(begin(b),end(b),val)-begin(b);
    return idx1+idx2>=res;
}

int value(int sizer,vector<int> &a,vector<int> &b)
{
    int i=1,j=2e9,ans=0;
    while(i<=j)
    {
        int mid=i+(j-i)/2;
        if(check(mid,a,b,sizer))
        {
            ans=mid;
            j=mid-1;
        }
        else
        {
            i=mid+1;
        }
    }    
    return ans;
}

class Solution{
    public:
    double MedianOfArrays(vector<int>& a, vector<int>& b)
    {
        int sizer=(a.size()+b.size());
        if(sizer%2)
        {
            return value((sizer+1)/2,a,b);
        }
        else
        {
            double val1=value(sizer/2,a,b);
            double val2=value((sizer/2)+1,a,b);
            return (val1+val2)/2;
        }
    
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends