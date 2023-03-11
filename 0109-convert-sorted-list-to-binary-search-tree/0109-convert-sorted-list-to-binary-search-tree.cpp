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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

TreeNode* dfs(ListNode* head,ListNode* tail)
{
    if(head==tail)
    {
        return NULL;
    }
    ListNode* s=head;
    ListNode* f=head;
    while(f!=tail&&f->next!=tail)
    {
        f=f->next->next;
        s=s->next;
    }
    TreeNode* root=new TreeNode(s->val);
    root->left=dfs(head,s);
    root->right=dfs(s->next,tail);
    return root;
}

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        
        return dfs(head,NULL);
    }
};