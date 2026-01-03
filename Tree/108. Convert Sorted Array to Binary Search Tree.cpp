#include <iostream>
#include <vector>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        
        return foo(nums, 0, nums.size() -1);
        
    }
    TreeNode* foo(std::vector<int>&nums, int left, int right){
        if(left > right) return nullptr;

        int middle = left + (right - left) / 2;

        int value = nums[middle];

        TreeNode* node = new TreeNode(value);

        node->left  = foo(nums, left, middle - 1);
        node->right = foo(nums, middle + 1, right); 

        return node;
    }

};

/*Input: nums = [-10,-3,0,5,9] sort = -10, -3, 0, 5, 9
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also */


int main()
{
    std::vector<int>nums = {-10, -3, 0, 5, 9};
    Solution s;
    TreeNode* res = s.sortedArrayToBST(nums);

    return 0;
}