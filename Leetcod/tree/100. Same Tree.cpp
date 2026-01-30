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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p || !q){
            if(!p && q || p && !q) return false;
            else return true;  
        } 
        std::cout << "cравнение: " << p->val << " = " << q->val << std::endl; 
        
        if(p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
// Input: p = [1,2,3], q = [1,2,3]


int main()
{
    TreeNode* b1 = new TreeNode(1);
    TreeNode* b2 = new TreeNode(2);
    TreeNode* b3 = new TreeNode(3);
    //TreeNode* b8 = new TreeNode(4);

    b1->left = b2;
    b1->right = b3;
    //b2->left = b8;

    TreeNode* b4 = new TreeNode(1);
    TreeNode* b5 = new TreeNode(2);
    TreeNode* b6 = new TreeNode(3);

    b4->left = b5;
    b4->right = b6;

    Solution s;
    std::cout << s.isSameTree(b1, b4);

    return 0;
}