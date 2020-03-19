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
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        helper(root, k, ans);
        return ans;
    }
private:
    void helper(TreeNode* root, int& k, int& ans) {
        if (!root || k <= 0)
            return;
        helper(root->left, k, ans);
        if (k == 1)
            ans = root->val;
        k--;
        helper(root->right, k, ans);
    }
};