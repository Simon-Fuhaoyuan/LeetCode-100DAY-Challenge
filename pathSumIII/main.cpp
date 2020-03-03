#include <iostream>
#include <queue>
#include <vector>
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
    int pathSum(TreeNode* root, int sum) {
        if (!root)
            return 0;
        queue<TreeNode*> node_que;
        queue<vector<int>> value_que;
        int ans = 0;
        vector<int> values, values_dup;
        TreeNode* tmp;
        node_que.push(root);
        value_que.push(vector<int>({root->val}));
        while (!node_que.empty()) {
            tmp = node_que.front();
            node_que.pop();
            values = value_que.front();
            value_que.pop();
            for (int i = 0; i < values.size(); ++i) {
                if (values[i] == sum)
                    ans++;
            }
            if (tmp->left) {
                values_dup.clear();
                values_dup.assign(values.begin(), values.end());
                for (int i = 0; i < values.size(); ++i)
                    values_dup[i] += tmp->left->val;
                values_dup.push_back(tmp->left->val);
                node_que.push(tmp->left);
                value_que.push(values_dup);
            }
            if (tmp->right) {
                for (int i = 0; i < values.size(); ++i)
                    values[i] += tmp->right->val;
                values.push_back(tmp->right->val);
                node_que.push(tmp->right);
                value_que.push(values);
            }
        }
        return ans;
    }
};