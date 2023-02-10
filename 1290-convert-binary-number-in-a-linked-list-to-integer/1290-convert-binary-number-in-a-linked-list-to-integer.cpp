ListNode* rev(ListNode* v)
{
    if(v==NULL||v->next==NULL)
    {
        return v;
    }
    ListNode* temp=rev(v->next);
    v->next->next=v;
    v->next=NULL;
    return temp;
}

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        if(head==NULL)
        {
            return 0;
        }
        ListNode* v=rev(head);
        int ans=0,cc=0;
        while(v!=NULL)
        {
            ans+=pow(2,cc)*v->val;
            // cout<<ans<<endl;
            v=v->next;
            cc++;
        }
        return ans;
    }
};