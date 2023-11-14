//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

typedef long long ll;
struct node
{
    node *nxt[2];
    node()
    {
        for(int i=0;i<2;i++)
        {
            this->nxt[i] = NULL;
        }
    }
};

node *root;

void insert_node(int x)
{
    node *curr = root;
    for(int i=31;i>=0;i--)
    {
        ll temp = (x >> i) & 1;
        if (curr->nxt[temp] == NULL)
        {
            curr->nxt[temp] = new node();
        }
        curr = curr->nxt[temp];
    }
}
 
int helper(int x)
{
    int ans=0;
    node* curr=root;
    for(int i=31;i>=0;i--)
    {
        int temp=(x >> i) & 1;
        if(curr->nxt[1-temp]!=NULL)
        {
            ans+=(1<<i);
            curr=curr->nxt[1-temp];
        }
        else
        {
            curr=curr->nxt[temp];
        }
    }
    return ans;
}

class Solution{   
public:
    int maxSubarrayXOR(int n, int arr[]){    
        root=new node();
        int ans=0,pref=0;
        insert_node(0);
        for(int i=0;i<n;i++)
        {
            pref^=arr[i];
            ans=max(ans,helper(pref));
            insert_node(pref);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.maxSubarrayXOR(N, arr) << endl;
    }
    return 0; 
} 

// } Driver Code Ends