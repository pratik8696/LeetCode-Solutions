//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

map<Node*,Node*> m;
map<int,Node*> hsh;
void bfs(Node *r)
{
    queue<Node*> q;
    q.push(r);
    while(q.size())
    {
        int curr=q.size();
        while(curr--)
        {
            Node* node=q.front();
            hsh[node->data]=node;
            q.pop();
            if(node->left!=NULL)
            {
                m[node->left]=node;
                q.push(node->left);
            }
            if(node->right!=NULL)
            {
                m[node->right]=node;
                q.push(node->right);
            }
        }
    }
}

class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        m.clear();
        hsh.clear();
        bfs(root);
        queue<Node*> q;
        map<Node*,int> dist,vis;
        q.push(hsh[target]);
        dist[hsh[target]]=0;
        vis[hsh[target]]=1;
        int ans=0;
        while(q.size())
        {
            int curr=q.size();
            while(curr--)
            {
                Node* node=q.front();
                ans=max(ans,dist[node]);
                q.pop();
                if(node->left!=NULL&&vis[node->left]==0)
                {
                    vis[node->left]=1;
                    dist[node->left]=dist[node]+1;
                    q.push(node->left);
                }
                if(node->right!=NULL&&vis[node->right]==0)
                {
                    vis[node->right]=1;
                    dist[node->right]=dist[node]+1;
                    q.push(node->right);
                }
                Node* parent=m[node];
                if(parent!=NULL&&vis[parent]==0)
                {
                    vis[parent]=1;
                    dist[parent]=dist[node]+1;
                    q.push(parent);
                }   
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends