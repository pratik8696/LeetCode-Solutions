void insert(int val,ListNode* &head,ListNode* &tail)
{
    ListNode* newNode=new ListNode(val);
    if(head==NULL)
    {
        head=newNode;
        tail=newNode;
        return;
    }
    tail->next=newNode;
    tail=tail->next;
}

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* a=NULL;
        ListNode* b=NULL;
        ListNode* c=NULL;
        ListNode* tempa=a;
        ListNode* tempb=b;
        ListNode* tempc=c;
        while(head!=NULL)
        {
            if(head->val<x)
            {
                insert(head->val,a,tempa);
            }
            else
            {
                insert(head->val,b,tempb);
            }
            head=head->next;
        }
        if(tempa==NULL)
        {
            return b;
        }
        tempa->next=b;
        return a;
    }
};