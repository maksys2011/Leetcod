#include <iostream>
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      if(head == nullptr || head->next == nullptr) return head;
      if(head->next->next == nullptr) return head; 
      ListNode* current = head;
      ListNode* prev = current;
      ListNode* next = head->next;
      while(next != nullptr){
        if(head->val == next->val){
          while(next != nullptr  && head->val == next->val) next = next->next;
          if(next == nullptr) return nullptr;
          else head = next;
        }
        if(current->val == next->val){
          while(next != nullptr  && head->val == next->val) next = next->next;
          if(next == nullptr){
            prev->next = nullptr;
            return head;
          }else{
            prev->next = next;

            
            current = next;
            next = next->next;
          }
          continue;
        }
        prev->next = current;
        current = current->next;
        next = next->next;
      }
      return head;
    }
};

//Input: head = [1,2,3,3,4,4,5] 1,4,5
//Output: [1,2,5]

int main()
{
    ListNode* l1 = new ListNode(1, nullptr);
    ListNode* l2 = new ListNode(2, nullptr);
    ListNode* l3 = new ListNode(3, nullptr);
    ListNode* l4 = new ListNode(3, nullptr);
    ListNode* l5 = new ListNode(4, nullptr);
    ListNode* l6 = new ListNode(4, nullptr);
    ListNode* l7 = new ListNode(5, nullptr);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = l7;
    Solution s;
    ListNode* result = s.deleteDuplicates(l1);
    while(result != nullptr){
      std::cout << result->val << " ";
      result = result->next;
    }




    return 0;
}