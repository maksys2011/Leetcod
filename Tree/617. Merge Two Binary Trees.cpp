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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        merge(root1, root2);   
        return root1;
    }
    void merge(TreeNode*& r1, TreeNode* r2){
        if(!r2) return;
        if(!r1){
            r1 = new TreeNode(r2->val);
        }else{
            r1->val = r1->val + r2->val; 
        }
        merge(r1->left, r2->left);
        merge(r1->right, r2->right);   
    }
};

void print(TreeNode* root){
    if(!root) return;
    print(root->left);
    print(root->right);
}


