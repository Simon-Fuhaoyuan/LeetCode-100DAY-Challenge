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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool flag_p = false, flag_q = false;
        TreeNode* ans = helper(root, p, q, flag_p, flag_q);
        if (ans)
            return ans;
        else
            return root;
    }
private:
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q, bool &flag_p, bool &flag_q) {
        if (!root->left && !root->right)
            return NULL;
        bool flag1 = false, flag2 = false;
        if (root->left) {
            TreeNode* pt = helper(root->left, p, q, flag1, flag2);
            if (pt)
                return pt;
            if (!flag1 && root->left == p)
                flag1 = true;
            if (!flag2 && root->left == q)
                flag2 = true;
            if (flag1 && flag2)
                return root->left;
        }
        bool flag3 = false, flag4 = false;
        if (root->right) {
            TreeNode* pt = helper(root->right, p, q, flag3, flag4);
            if (pt)
                return pt;
            if (!flag3 && root->right == p)
                flag3 = true;
            if (!flag4 && root->right == q)
                flag4 = true;
            if (flag3 && flag4)
                return root->right;
        }
        flag_p = flag1 || flag3;
        flag_q = flag2 || flag4;
        if (flag_p && flag_q)
            return root;
        else
            return NULL;
    }
};