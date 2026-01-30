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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return foo(root, subRoot);
    }

    bool foo(TreeNode* root, TreeNode* subRoot){
        if(!root) return false;
        else{
            if(foo1(root, subRoot))return true;
            if(foo(root->left, subRoot)) return true;
            if(foo(root->right, subRoot)) return true;
            return false;
        }
    }

    bool foo1(TreeNode* root, TreeNode* subRoot){
        if(!root && subRoot || root && !subRoot) return false;
        if(!root && !subRoot) return true;
        if(root->val == subRoot->val){
            if(!foo1(root->left, subRoot->left) || 
                !foo1(root->right, subRoot->right)){
                    return false;
                }
            return true;
        }else{
            return false;
        }
    }
};
