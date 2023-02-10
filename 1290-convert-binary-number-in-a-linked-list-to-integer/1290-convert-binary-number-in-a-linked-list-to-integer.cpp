class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            ListNode* fwd=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fwd;
        }
        int ans=0,cc=0;
        while(prev!=NULL)
        {
            // cout<<prev->val<<" ";
            ans+=pow(2,cc)*prev->val;
            prev=prev->next;
            cc++;
        }
        // cout<<endl;
        return ans;
    }
};