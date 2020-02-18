#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * HINT: Note that this problem is for path!!!
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxPathSum(root, ans);
        return ans;
    }
private:
    int maxPathSum(TreeNode *node, int &ans) {
        if (!node)
            return 0;
        
        int left = max(0, maxPathSum(node->left, ans));
        int right = max(0, maxPathSum(node->right, ans));
        ans = max(ans, left + right + node->val);

        return node->val + max(left, right);
    }
};