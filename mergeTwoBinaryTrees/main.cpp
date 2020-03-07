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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2)
            return NULL;
        if (!t1)
            return t2;
        if (!t2)
            return t1;
        t1->val += t2->val;
        TreeNode* left = mergeTrees(t1->left, t2->left);
        TreeNode* right = mergeTrees(t1->right, t2->right);
        t1->left = left;
        t1->right = right;
        return t1;
    }
};