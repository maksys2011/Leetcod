#include <iostream>
#include <vector>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int v) : val(v), left(nullptr), right(nullptr){}
    TreeNode(int v, TreeNode* l, TreeNode* r) :
        val(v), left(l), right(r){};
};

class Solution {
public:
    std::vector<TreeNode*> generateTrees(int n) {
        
    }
};

int main()
{
    std::vector<int>;

    return 0;
}