#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        vector<int> level;
        stack<TreeNode*> stk1, stk2;
        bool turn = true; // true for left first, false for right first
        stk1.push(root);
        TreeNode* tmp;
        while (!stk1.empty() || !stk2.empty()) {
            level.clear();
            while (!stk1.empty()) {
                tmp = stk1.top(); stk1.pop();
                level.push_back(tmp->val);
                if (tmp->left)
                    stk2.push(tmp->left);
                if (tmp->right)
                    stk2.push(tmp->right);
            }
            if (!level.empty())
                ans.push_back(level);
            level.clear();
            while (!stk2.empty()) {
                tmp = stk2.top(); stk2.pop();
                level.push_back(tmp->val);
                if (tmp->right)
                    stk1.push(tmp->right);
                if (tmp->left)
                    stk1.push(tmp->left);
            }
            if (!level.empty())
                ans.push_back(level);
        }
        return ans;
    }
};