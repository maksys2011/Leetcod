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
    void reorderList(ListNode* head) { 
        if(!head || !head->next|| !head->next->next) return;
        ListNode* current = head;
        while(current->next != nullptr){
            ListNode* prev = current;
            ListNode* tmp = current->next;
            while(tmp->next!= nullptr){
                tmp = tmp->next;
                prev = prev->next;
            }
            prev->next =nullptr;
            ListNode* l1 = current->next;
            current->next = tmp;
            tmp->next = l1;
            if(tmp->next == nullptr) return;
            current = tmp->next;
        }
    }
};


