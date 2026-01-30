#include <iostream>
#include <vector>
#include <string>
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
    int max = 0;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        edge_counting(root);
        return max;
    }
    int edge_counting(TreeNode* root){
        if(!root) return 0;

        int left  = edge_counting(root->left);
        int right = edge_counting(root->right);

        max = 1 + std::max(max, left + right);

        return std::max(left, right) + 1;

     }
};

