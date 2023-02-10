typedef ListNode N;
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
        {
            return head;
        }
        N* a=head;
        N* b=head;
        
        do
        {
            a=a->next;
            if(a!=NULL)
            {
                a=a->next;
            }
            b=b->next;
        }
        while(a!=NULL && b!=NULL && a!=b);
        
        if(a==NULL||b==NULL)
        {
            return NULL;
        }
        
        // cout<<a->val<<" "<<b->val<<endl;
        b=head;
        
        while(a!=b)
        {
            a=a->next;
            b=b->next;
        }
        
        return a;
    }
};