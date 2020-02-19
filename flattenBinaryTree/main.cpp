#include <iostream>
#include <stack>
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
    void flatten(TreeNode* root) {
        if (!root)
            return;
        stack<TreeNode*> stk;
        stk.push(root->right);
        stk.push(root->left);
        root->left = NULL;
        TreeNode *tmp = root;
        while (!stk.empty()) {
            if (stk.top()) { // not null
                tmp->right = stk.top();
                stk.pop();
                tmp = tmp->right;
                stk.push(tmp->right);
                stk.push(tmp->left);
                tmp->left = NULL;
            }
            else
                stk.pop();
        }
    }
};