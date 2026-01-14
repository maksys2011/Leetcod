#include <set>

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
    bool findTarget(TreeNode* root, int k) {
        std::set<int>table;
        return foo(root, table, k);
        
    }
    bool foo(TreeNode* root, std::set<int>& table, int k){
        if(!root) return false;
        if(table.count(k - root->val)) return true;
        else{
            table.insert(root->val);
            return foo(root->left, table, k) || foo(root->right, table, k);
        } 
    }
};