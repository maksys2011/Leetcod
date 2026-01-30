#include <iostream>
#include <vector>

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
    std::vector<int>v1;
    std::vector<int>v2;
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        foo(root1, v1);
        foo(root2, v2);
        print_vector(v1);
        print_vector(v2);
        if(v1.size() != v2.size()) return false;
        for(size_t i  = 0; i < v1.size(); ++i){
            if(v1[i] != v2[i]) return false;
        }
        return true;
    }
    
    void foo(TreeNode* root, std::vector<int>& v){
        if(!root) return;
        
        if(!root->left && !root->right){
            v.push_back(root->val);
        }
        foo(root->left, v);
        foo(root->right, v);
    }

    void print_vector(std::vector<int>& v){
        for(const auto& it : v){
            std::cout << it << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    TreeNode* b1 = new TreeNode(3);
    TreeNode* b2 = new TreeNode(5);
    TreeNode* b3 = new TreeNode(6);
    TreeNode* b4 = new TreeNode(2);
    TreeNode* b5 = new TreeNode(7);
    TreeNode* b6 = new TreeNode(4);
    TreeNode* b7 = new TreeNode(1);
    TreeNode* b8 = new TreeNode(9);
    TreeNode* b9 = new TreeNode(8);

    b1->left  = b2;
    b1->right = b7;
    b2->left  = b3;
    b2->right = b4;
    b4->left  = b5;
    b4->right = b6;
    b7->right = b8;
    b8->right = b9;

    TreeNode* b10 = new TreeNode(3);
    TreeNode* b11 = new TreeNode(5);
    TreeNode* b12 = new TreeNode(1);
    TreeNode* b13 = new TreeNode(6);
    TreeNode* b15 = new TreeNode(7);
    TreeNode* b16 = new TreeNode(4);
    TreeNode* b17 = new TreeNode(2);
    TreeNode* b18 = new TreeNode(9);
    TreeNode* b19 = new TreeNode(8);

    b10->left  = b11;
    b10->right = b12;
    b11->left  = b13;
    b11->right = b15;
    b12->left  = b16;
    b12->right = b17;
    b17->left  = b18;
    b17->right = b19;

    Solution s;
    std::cout << s.leafSimilar(b1, b10);

    return 0;
}