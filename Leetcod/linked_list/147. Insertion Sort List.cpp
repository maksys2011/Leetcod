struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
      if(!head || !head->next) return head;
      ListNode* dummy = new ListNode(0);
      ListNode* current = head;
      
      while(current != nullptr){
        ListNode* prev = dummy;
        ListNode* next = current->next;
        while(prev->next != nullptr && prev->next->val < current->val){
          prev = prev->next;
        }
        
        current->next = prev->next;
        prev->next = current;
        
        current = next;
      }
      ListNode* result = dummy->next;
      delete dummy;
      return result;
    }
};