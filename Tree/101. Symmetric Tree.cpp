#include <iostream>
#include <stack>

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
    bool isSymmetric(TreeNode* root) {
        return comparison_of_elemenst(root);
    }
    bool comparison_of_elemenst(TreeNode* root){
        if(root == nullptr) return true;
        if(!root->left && root->right || root->left && !root->right) return false;
        TreeNode* root_left = root->left;
        TreeNode* root_right = root->right;
        if(root_left->val != root->right->val) return false;
        std::stack<TreeNode*> s1, s2;
        while(root_left != nullptr || root_right != nullptr || !s1.empty() || !s2.empty()){
            while(root_left != nullptr || root_right != nullptr){
                if(root_left  == nullptr || root_right == nullptr) return false;
                s1.push(root_left);
                root_left = root_left->left;
                s2.push(root_right);
                root_right = root_right->right;
            }
            root_left  = s1.top();
            root_right = s2.top();
            
            s1.pop();
            s2.pop();

            if(root_left->val != root_right->val) return false;
            
            root_left = root_left->right;
            root_right = root_right->left;
        }

        return true;  
    }
};



//Input: root = [1,2,2,3,4,4,3]
// Output: true


int main()
{
    TreeNode* b1 = new TreeNode(1);
    TreeNode* b2 = new TreeNode(2);
    TreeNode* b3 = new TreeNode(7);
    TreeNode* b4 = new TreeNode(3);
    TreeNode* b5 = new TreeNode(4);
    TreeNode* b6 = new TreeNode(4);
    TreeNode* b7 = new TreeNode(3);

     /*               1 b1
                   / \ 
            b2    2   2     b3
                 / \ / \
       */         

    b1->left  = b2;
    b1->right = b3;
    b2->left  = b4;
    b2->right = b5;
    b3->left  = b6;
    b3->right = b7;

    Solution s;
    std::cout << s.isSymmetric(b1);
    std::cout << std::endl;
    std::cout << "hello ubuntu" << std::endl;

    return 0;
}