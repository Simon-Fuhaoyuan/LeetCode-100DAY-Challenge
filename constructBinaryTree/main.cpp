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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty())
            return NULL;
        return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
private:
    TreeNode* buildTree(vector<int>::iterator pre_begin, vector<int>::iterator pre_end, 
    vector<int>::iterator in_begin, vector<int>::iterator in_end) {
        if (pre_begin == pre_end)
            return NULL;
        int root_val = *pre_begin;
        TreeNode *root = new TreeNode(root_val);
        int left_cnt = 0;
        while (*(in_begin + left_cnt) != root_val)
            left_cnt++;
        int right_cnt = pre_end - pre_begin - left_cnt - 1;
        root->left = buildTree(pre_begin + 1, pre_begin + 1 + left_cnt, in_begin, in_begin + left_cnt);
        root->right = buildTree(pre_end - right_cnt, pre_end, in_end - right_cnt, in_end);
        return root;
    }
};