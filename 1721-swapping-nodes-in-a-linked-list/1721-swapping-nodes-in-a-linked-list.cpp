/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* a = head;
        ListNode* b = head;
        ListNode* c = head;
        int cc=0;
        while(a!=NULL)
        {
            a=a->next;
            cc++;
        }
        a=head;
        int last=cc-k;
        int front=k-1;
        while(front--)
        {
            b=b->next;
        }
        while(last--)
        {
            c=c->next;
        }
        swap(b->val,c->val);
        return head;
    }
};