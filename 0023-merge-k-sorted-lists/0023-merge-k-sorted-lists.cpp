typedef ListNode N;

N* merge(N* a,N* b)
{
    N* curr1=a;
    N* curr2=b;
    N* next1=a->next;
    N* next2=NULL;
    while(curr1!=NULL&&curr2!=NULL)
    {
        int p=curr1->val,q=curr2->val,r=next1->val;
        if(p<=q&&q<=r)
        {
            // curr1->curr2->next1
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;
            curr1=curr2;
            curr2=next2;
        }
        else
        {
            curr1=next1;
            if(curr1->next==NULL)
            {
                curr1->next=curr2;
                break;
            }
            next1=next1->next;
        }
    }
    return a;
}

ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if(a==NULL)
        {
            return b;
        }
        if(b==NULL)
        {
            return a;
        }
        if(a->val>b->val)
        {
            swap(a,b);
        }
        if(a->next==NULL)
        {
            a->next=b;
            return a;
        }
        return merge(a,b);
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        N* head=NULL;
        int i=0;
        while(i < n && lists[i]==NULL)
        {
            i++;
        }
        if(i==n)
        {
            return NULL;
        }
        cout<<i<<endl;
        head=lists[i];
        i++;
        for(;i<n;i++)
        {
            head=mergeTwoLists(head,lists[i]);
        }
        return head;
    }
};