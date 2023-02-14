//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        Node* first=NULL;
        Node* first_last=first;
        Node* second=NULL;
        Node* second_last=second;
        Node* curr=head;
        
        while(curr!=NULL)
        {
            if(curr->data%2)
            {
                if(first==NULL)
                {
                    first=curr;
                    first_last=first;
                }
                else
                {
                    first_last->next=curr;
                }
                first_last=curr;
                curr=curr->next;
                first_last->next=NULL;
            }
            else
            {
                if(second==NULL)
                {
                    second=curr;
                    second_last=second;
                }
                else
                {
                    second_last->next=curr;
                }
                second_last=curr;
                curr=curr->next;
                second_last->next = NULL;
            }
        }
        if(first!=NULL&&second!=NULL)
        {
            second_last->next=first;
            return second;
        }
        else if(first!=NULL)
        {
            return first;
        }
        return second;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends