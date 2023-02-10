typedef ListNode N;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)
        {
            return head;
        }
        
        N* curr=head;
        N* prev=NULL;
        N* next = NULL;
        
        N* t=head;
        int cc=0;
        while(cc<k&&t!=NULL)
        {
            t=t->next;
            cc++;
        }
        
        if(cc!=k)
        {
            return head;
        }
        
        int count=0;
        while(count<k&&curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        
        if(next!=NULL)
        {
            head->next=reverseKGroup(next,k);
        }
        
        return prev;
    }
};