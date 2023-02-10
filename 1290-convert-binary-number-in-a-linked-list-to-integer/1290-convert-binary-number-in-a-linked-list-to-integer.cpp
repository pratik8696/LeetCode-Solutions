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

ListNode* head;

void reverse(ListNode* curr,ListNode* prev)
{
    if(curr==NULL)
    {
        head=prev;
        return;
    }
    reverse(curr->next,curr);
    curr->next=prev;
}



class Solution {
public:
    int getDecimalValue(ListNode* x) {
        head=x;
        ListNode* prev=NULL;
        reverse(x,prev);
        ListNode* v=head;
        int ans=0,cc=0;
        while(v!=NULL)
        {
            // cout<<v->val<<" ";
            ans+=pow(2,cc)*v->val;
            v=v->next;
            cc++;
        }
        // cout<<endl;
        return ans;
    }
};