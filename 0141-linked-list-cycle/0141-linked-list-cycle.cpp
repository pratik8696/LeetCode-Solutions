/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL)
        {
            return false;
        }
        ListNode *s=head;
        ListNode *f=head->next;
        while(s!=f&&s!=NULL&&f!=NULL&&s->next!=NULL&&f->next!=NULL&&f->next->next!=NULL)
        {
            s=s->next;
            f=f->next;
            f=f->next;
        }
        return s==f;
    }
};