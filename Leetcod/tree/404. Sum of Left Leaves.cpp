#include <iostream>
#include <vector>
#include <string>

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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum;
        sum_left(root, sum);
        return sum;
    }
    void sum_left(TreeNode* root, int& sum){
        if(!root) return;

        if(root->left != nullptr) sum = sum + root->left->val;
        sum_left(root->left, sum);
        sum_left(root->right, sum);

    }
};

/*                      5
                    /       \
                   4         8
                /   \       /   \
               11    null  13    4
            /     \             /  \
           7       2           1    null



*/

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
    int res = s.sumOfLeftLeaves(b1);
    std::cout << "result : " << res << std::endl;
    std::cout << std::endl;
     
    return 0;
}