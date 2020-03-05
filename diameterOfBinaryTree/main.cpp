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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
private:
    int helper(TreeNode *root, int& max_d) {
        if (root == NULL)
            return 0;
        int left_cnt = helper(root->left, max_d);
        int right_cnt = helper(root->right, max_d);
        if (left_cnt + right_cnt + 1 > max_d)
            max_d = left_cnt + right_cnt;
        return max(left_cnt, right_cnt) + 1;
    }
};