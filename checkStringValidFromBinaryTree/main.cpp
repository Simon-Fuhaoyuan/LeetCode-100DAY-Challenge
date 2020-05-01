#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return helper(root, arr, 0);
    }
private:
    bool helper(TreeNode* root, vector<int>& arr, int index) {
        if (!root || root->val != arr[index])
            return false;
        if (index == arr.size() - 1)
            return !root->left && !root->right;
        index++;
        return helper(root->left, arr, index) || helper(root->right, arr, index);
    }
};