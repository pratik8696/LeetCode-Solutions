//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends

Node* findIntersection(Node* head1, Node* head2)
{
    Node* a=head1;
    Node* b=head2;
    Node* v=NULL;
    Node* ve=NULL;
    while(a!=NULL&&b!=NULL)
    {
        if(a->data==b->data)
        {
            if(v==NULL)
            {
                v=a;
                ve=v;
            }
            else
            {
                ve->next=a;
                ve=a;
            }
            a=a->next;
            b=b->next;
        }
        else if(a->data<b->data)
        {
            a=a->next;
        }
        else
        {
            b=b->next;
        }
    }
    if(ve!=NULL)
    {
        ve->next=NULL;
    }
    return v;
}