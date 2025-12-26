struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* left = head;
        ListNode* middle = searching_for_the_middle(head);
        ListNode* right = middle->next;
        middle->next = nullptr;

        left = sortList(left);
        right = sortList(right);

        return mergesort(left, right);
    }
    ListNode* searching_for_the_middle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }  

    ListNode* mergesort(ListNode* l1, ListNode* l2){
        ListNode res(0);
        ListNode* tmp = &res;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val <= l2->val){
                tmp->next = l1;
                l1 = l1->next;
            }else{
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp->next;
        }
        if (l1 != nullptr) tmp->next = l1;
        if (l2 != nullptr) tmp->next = l2;
        return res.next;
    }
};
