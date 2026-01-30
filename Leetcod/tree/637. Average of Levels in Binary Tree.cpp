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
private:
    struct sum_and_number_ofElements
    {
      double sum   = 0;
      size_t count = 0;
    };
public:
    void foo(TreeNode* root, int level, std::vector<sum_and_number_ofElements>& nums){
      if(!root) return;  
      
      if(level >= nums.size()){
        nums.push_back({0, 0});
      }
      
      nums[level].sum += root->val;
      nums[level].count++;
      
      foo(root->left, level + 1, nums);
      foo(root->right, level + 1, nums);
    }
    std::vector<double> averageOfLevels(TreeNode* root) {
        std::vector<double>result;
        std::vector<sum_and_number_ofElements>nums;
        foo(root, 0, nums);
        
        for(const auto& it : nums){
          result.push_back(it.sum / it.count);
        }
        return result;
    }
};