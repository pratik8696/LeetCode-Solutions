//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            res.push_back(i);
        }
        while(res.size()!=1)
        {
            int first=res.back();
            res.pop_back();
            int second=res.back();
            res.pop_back();
            if(M[first][second]==1)
            {
                res.push_back(second);
            }
            else
            {
                res.push_back(first);
            }
        }
        for(int i=0;i<M[res.back()].size();i++)
        {
            if(M[res.back()][i])
            {
                return -1;
            }
            if(M[i][res.back()]==0&&i!=res.back())
            {
                return -1;
            }
        }
        return res.back();
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends