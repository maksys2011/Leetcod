struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr || head->next == nullptr) return head; 
        int count = 1;
        ListNode* elements = head;
        while(elements != nullptr){
            elements = elements->next;
            count++;
        }
        if(count == left * right){
            return reverseList(head);
        }else count = 1;
        ListNode* prev = new ListNode(0, head);
        ListNode* current = head;
        
        if(left > 1){
        while(current != nullptr){
            if(count == left){
                ListNode* first = current;
                while(current != nullptr && count != right){
                    current = current->next;
                    count++;
                }
                ListNode* second = current;
                ListNode* tmp = current->next;
                second->next = nullptr;
                ListNode* rev = reverseList(first);
                prev->next = rev;
                while(rev->next != nullptr){
                    rev = rev->next;
                }
                rev->next = tmp;
            }
            prev = prev->next;
            current = current->next;
            count++;
        }
    }

        if(left <= 1){
            while(current != nullptr){
                if(count == right){
                    ListNode* tmp = current->next;
                    current->next = nullptr;
                    head = reverseList(prev->next);
                    ListNode* prev = head;
                    while(prev->next != nullptr) prev = prev->next;
                    prev->next = tmp; 
                }
                count++;
                current = current->next;
            }
        }

        return head;
    }
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* current = head;
        while(current != nullptr){
            ListNode* next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node; 
        }
        return prev;

    }
};