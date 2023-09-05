class Solution {
public:
    Node* copyRandomList(Node* head) {
      if (!head) return nullptr;
      Node* head_cp = nullptr, *curr_cp = nullptr, *curr = head;
      
      // Interleave the copied list with the original list
      // so that curr->next is the corresponding copied node and copied->next is the next node
      while (curr) {
        curr_cp = new Node(curr->val, curr->next, nullptr);
        curr->next = curr_cp;
        curr = curr_cp->next;
      }
      
      // Set the copied->random for the copied list using the property that curr->next is the corresponding copied node
      curr = head;
      while (curr) {
        curr_cp = curr->next;
        if (curr->random) 
          curr_cp->random = curr->random->next;
        curr = curr_cp->next;        
      }
      
      // Separate the lists and restore the pointers for the original and copied lists
      curr = head;
      head_cp = head->next;
      while (curr) {
        curr_cp = curr->next;
        curr->next = curr_cp->next;
        curr = curr->next;
        if (curr)
          curr_cp->next = curr->next;
      }
      
      // Return the head of the copied list
      return head_cp;
    }
};
