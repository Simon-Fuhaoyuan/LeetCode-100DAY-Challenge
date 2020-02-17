#include <iostream>
#include <stack>
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodes;
        stack<int> times;
        vector<int> inorder;
        TreeNode *tmp;
        int curr_time;
        // push root
        if (root) {
            nodes.push(root);
            times.push(0);
        }
        // traverse
        while (!nodes.empty()) {
            tmp = nodes.top(); nodes.pop();
            curr_time = times.top(); times.pop();
            if (++curr_time < 2) {
                nodes.push(tmp);
                times.push(curr_time);
                if (tmp->left) {
                    nodes.push(tmp->left);
                    times.push(0);
                }
            }
            else {
                inorder.push_back(tmp->val);
                if (tmp->right) {
                    nodes.push(tmp->right);
                    times.push(0);
                }
            }
        }
        return inorder;
    }
};