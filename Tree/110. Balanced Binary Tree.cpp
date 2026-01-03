#include <iostream>
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
    bool isBalanced(TreeNode* root) {
        return foo(root) != -1;
    }
    int foo(TreeNode* root)
    {
        if(root == nullptr) return 0;

        int left_val = foo(root->left);

        if(left_val == -1) return -1;

        int right_val = foo(root->right);

        if(right_val == -1) return -1;

        if((left_val - right_val) > 1) return - 1;

        return 1 + std::max(foo(root->left), foo(root->right));
    }
};

int main()
{
    TreeNode* b1 = new TreeNode(1);
    TreeNode* b2 = new TreeNode(2);
    TreeNode* b3 = new TreeNode(7);
    TreeNode* b4 = new TreeNode(3);
    TreeNode* b5 = new TreeNode(4);
    TreeNode* b6 = new TreeNode(4);
    TreeNode* b7 = new TreeNode(3);

    b1->left  = b2;
    b1->right = b3;
    b2->left  = b4;
    b4->left = b5;
    b5->left = b6;

    Solution s;
    std::cout << s.isBalanced(b1);
    std::cout << std::endl;


    return 0;
}