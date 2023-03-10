vector<int> arr;
class Solution {
public:
    Solution(ListNode* head) {
        arr.clear();
        ListNode* curr=head;
        while(curr!=NULL)
        {
            arr.push_back(curr->val);
            curr=curr->next;
        }
    }
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};