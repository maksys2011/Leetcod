#include <iostream>

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
    int countNodes(TreeNode* root) {
        int c = 0;
        count(root, c);
        return c;
    }

    void count(TreeNode* root, int& c){
        if(!root) return;
        c++;
        count(root->left, c);
        count(root->right,c);
    }
};

int main()
{
    TreeNode* b1 = new TreeNode(5);
    TreeNode* b2 = new TreeNode(4);
    TreeNode* b3 = new TreeNode(8);
    TreeNode* b4 = new TreeNode(11);
    TreeNode* b5 = new TreeNode(13);
    TreeNode* b6 = new TreeNode(4);
    TreeNode* b7 = new TreeNode(7);
    TreeNode* b8 = new TreeNode(2);
    TreeNode* b9 = new TreeNode(1);

    b1->left  = b2;
    b1->right = b3;
    b2->left  = b4;
    b4->left  = b7;
    b4->right = b8;
    b3->left  = b5;
    b3->right = b6;
    b6->right = b9;

    Solution s;
    std::cout << s.countNodes(b1);
    std::cout << std::endl;
     
    return 0;
}