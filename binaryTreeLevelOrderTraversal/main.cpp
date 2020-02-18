#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> tmp;
        vector<queue<TreeNode*>> que(2, queue<TreeNode*>());
        TreeNode *curr;
        int turn = 0;
        bool flag_switch = true;

        if (root)
            que[0].push(root);
        while (!que[0].empty() || !que[1].empty()) {
            tmp.clear();
            if (flag_switch)
                turn = 0;
            else
                turn = 1;
            while (!que[turn].empty()) {
                curr = que[turn].front(); que[turn].pop();
                tmp.push_back(curr->val);
                if (curr->left)
                    que[1 - turn].push(curr->left);
                if (curr->right)
                    que[1 - turn].push(curr->right);
            }
            ans.push_back(tmp);
            flag_switch = !flag_switch;
        }

        return ans;
    }
};