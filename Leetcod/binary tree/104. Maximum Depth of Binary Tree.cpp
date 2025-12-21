#include <algorithm>

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
    int maxDepth(TreeNode* root) {
        int left = 0;
        int right = 0;
        
        if(root == nullptr){
            return 0;
            
        }else{
            left = maxDepth(root->left);
            right =  maxDepth(root->right);
            return std::max(left, right) + 1;
        }
    }
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return 1;
        if(root->left == nullptr){
            return minDepth(root->right) + 1;
        }
        else if(root->right == nullptr){
            return minDepth(root->right) + 1;
        }else{
            return 1 + std::min(minDepth(root->left), minDepth(root->right));
        }
    }
};

