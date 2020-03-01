#include <iostream>
#include <unordered_map>
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
    int rob(TreeNode* root) {
        if (!root)
            return 0;
        unordered_map<TreeNode*, int> hashMap;
        helper(root, hashMap);
        return hashMap[root];
    }
private:
    void helper(TreeNode* node, unordered_map<TreeNode*, int>& hashMap) {
        if (hashMap.count(node))
            return;
        int child1 = 0, child2 = 0;
        int grandchild1 = 0, grandchild2 = 0, grandchild3 = 0, grandchild4 = 0;
        if (node->left) {
            helper(node->left, hashMap);
            child1 = hashMap[node->left];
            if (node->left->left) {
                helper(node->left->left, hashMap);
                grandchild1 = hashMap[node->left->left];
            }
            if (node->left->right) {
                helper(node->left->right, hashMap);
                grandchild1 = hashMap[node->left->right];
            }
        }
        if (node->right) {
            helper(node->right, hashMap);
            child2 = hashMap[node->right];
            if (node->right->left) {
                helper(node->right->left, hashMap);
                grandchild3 = hashMap[node->right->left];
            }
            if (node->right->right) {
                helper(node->right->right, hashMap);
                grandchild4 = hashMap[node->right->right];
            }
        }
        int max_val = max(node->val + grandchild1 + grandchild2 + grandchild3 + grandchild4, child1 + child2);
        hashMap.insert(make_pair(node, max_val));
    }
};