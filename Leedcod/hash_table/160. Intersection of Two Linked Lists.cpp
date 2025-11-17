struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        ListNode* A = headA;
        ListNode* B = headB;
        ListNode* tmp = A;
        while (B != nullptr) {
            A = tmp;
            while (A != nullptr) {
                if (A == B) return A;
                else A = A->next;
            }
            B = B->next;
        }
        return nullptr;
    }
};