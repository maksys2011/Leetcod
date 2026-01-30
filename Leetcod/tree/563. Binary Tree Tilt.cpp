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
private:
    int result = 0;
public:
    int findTilt(TreeNode* root) {
        calculator(root);
        return result;
    }
    int calculator(TreeNode* root){
        if(!root) return 0;

        int left  = calculator(root->left);
        int right = calculator(root->right);
        result += std::abs(left - right);
        return left + right + root->val;
    }
};
