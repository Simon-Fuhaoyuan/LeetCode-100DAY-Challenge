#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root->left, root->right);
    }
private:
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (!left && !right)
            return true;
        if (!left || !right)
            return false;
        if (left->val != right->val)
            return false;
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};