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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<int> arr;
        while(head!=NULL)
        {
            arr.push_back(head->val);
            head=head->next;
        }
        vector<vector<int>> v;
        vector<int> temp;
        for(auto t:arr)
        {
            int size_req=arr.size()/k+(v.size()>=arr.size()%k?0:1);
            if(temp.size()==size_req)
            {
                v.push_back(temp);
                temp.clear();
            }
            temp.push_back(t);
        }
        while(v.size()!=k)
        {
            v.push_back(temp);
            temp.clear();
        }
        vector<ListNode*> ans;
        for(auto t:v)
        {
            ListNode* tt=NULL;
            ListNode* back=NULL;
            for(auto x:t)
            {
                if(tt==NULL)
                {
                    tt=new ListNode(x);
                    tt->next=NULL;
                    back=tt;
                }
                else
                {
                    back->next=new ListNode(x);
                    back=back->next;
                }
                // cout<<x<<" ";
            }
            ans.push_back(tt);
            // cout<<endl;
        }
        return ans;
    }
};