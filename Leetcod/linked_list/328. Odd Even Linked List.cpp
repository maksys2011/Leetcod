struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
   ListNode* oddEvenList(ListNode* head) {
      if(!head || !head) return head;
      ListNode dummy(0);
      ListNode dummy2(0);
      ListNode* tmp = &dummy;
      ListNode* tmp2 = &dummy2;
      ListNode* current = head;
      int index = 1;
      while(current != nullptr){
          if(index % 2 == 0){
            tmp->next = current;
            tmp = tmp->next;
          }else{
            tmp2->next = current;
            tmp2 = tmp2->next;
            if(current->next == nullptr) tmp2->next = nullptr;
          }
        current = current->next;  
        index++;
    }
    tmp->next = nullptr;
    tmp2->next = dummy.next;
    return dummy2.next;
}
};
