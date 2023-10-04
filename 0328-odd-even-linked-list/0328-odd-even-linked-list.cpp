class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd=NULL;
        ListNode* even=NULL;
        ListNode* fodd=NULL;
        ListNode* feven=NULL;
        int cc=1;
        while(head!=NULL)
        {
            if(cc%2==0)
            {
                if(even==NULL)
                {
                    even=head;
                    feven=head;
                    // feven->next=NULL;
                }
                else
                {
                    feven->next=head;
                    feven=head;
                    // feven->next=NULL;
                }
            }
            else
            {
                if(odd==NULL)
                {
                    odd=head;
                    fodd=head;
                    // fodd->next=NULL;
                }
                else
                {
                    fodd->next=head;
                    fodd=head;
                    // fodd->next=NULL;
                }
            }
            cc++;
            head=head->next;
        }
        if(feven)   feven->next=NULL;
        if(fodd) fodd->next=NULL;
        if(odd!=NULL)
        {
            fodd->next = even;
        }
        else 
        {
            return even;
        }
        return odd;
    }
};