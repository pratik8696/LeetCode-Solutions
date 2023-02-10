typedef ListNode N;
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
        {
            return NULL;
        }
        N* curr=head;
        int cc=1;
        while(curr->next!=NULL)
        {
            curr=curr->next;
            cc++;
        }
        curr->next=head;
        curr=head;
        k%=cc;
        int steps=cc-k;
        N* prev=NULL;
        N* v=head;
        while(steps--)
        {
            prev=v;
            v=v->next;
        }
        prev->next=NULL;
        cout<<prev->val<<" "<<v->val<<endl;
        return v;
    }
};