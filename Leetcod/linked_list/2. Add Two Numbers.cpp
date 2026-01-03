#include <vector>
#include <algorithm>

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* tmp1 = l1;
      ListNode* tmp2 = l2;
      ListNode result(0, nullptr);
      std::vector<int> nums1, nums2;
      Convert_to_vector(nums1, nums2, l1, l2);
      int n = nums1.size() - 1;
      int min_n = nums2.size() - 1;
      int remainder_ = 0;
      ListNode* tmp = &result;
      while(n >= 0 && min_n >= 0){
        int res = (nums1[n] + nums2[min_n]) + remainder_;
        if(res >= 10){
          res = res - 10;
          ListNode* l1 = new ListNode(res, nullptr);
          tmp->next = l1;
          tmp = tmp->next;
          remainder_ = 1;
        }else{
          ListNode* l2 = new ListNode(res, nullptr);
          remainder_ = 0;
          tmp->next = l2;
          tmp = tmp->next;
        }
        n--;
        min_n--;
      }
      if(n > -1){
        while(n >= 0){
          int res = nums1[n] + remainder_ ;
          if(res >= 10){
            res = res - 10;
            ListNode* l3 = new ListNode(res, nullptr);
            tmp->next = l3;
            tmp = tmp->next;
            remainder_ = 1;
          }else{
            ListNode* l4 = new ListNode(res, nullptr);
            tmp->next = l4;
            tmp = tmp->next;
            remainder_ = 0;
          }
          n--;
        }
      }
      
      if(min_n > -1){
        while(min_n >= 0){
          int res = nums2[min_n] + remainder_ ;
          if(res >= 10){
            res = res - 10;
            ListNode* l5 = new ListNode(res, nullptr);
            tmp->next = l5;
            tmp = tmp->next;
            remainder_ = 1;
          }else{
            ListNode* l6 = new ListNode(res, nullptr);
            tmp->next = l6;
            tmp = tmp->next;
            remainder_ = 0;
          }
          min_n--;
        }
      }
      
      if(remainder_ == 1){
        ListNode* l6 = new ListNode(remainder_, nullptr);
        tmp->next = l6;
        tmp = tmp->next;
      }

      return result.next;  
    }
    
    void Convert_to_vector (std::vector<int>&nums1,
                        std::vector<int>&nums2,
                          ListNode* l1,
                          ListNode* l2){
                            
      ListNode* list1 = l1;
      ListNode* list2 = l2;
      while(list1 != nullptr){
        nums1.push_back(list1->val);
        list1 = list1->next;
      }
      while(list2 != nullptr){
        nums2.push_back(list2->val);
        list2 = list2->next;
      }
      std::reverse(nums1.begin(), nums1.end());
      std::reverse(nums2.begin(), nums2.end());
    } 
};