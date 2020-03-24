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
    int maxAncestorDiff(TreeNode* root) {
        vector<int> candidates;
        int ans = 0;
        helper(root, candidates, ans);
        return ans;
    }
private:
    void helper(TreeNode* root, vector<int> &candidates, int& ans) {
        if (!root)
            return;
        int tmp1, tmp2;
        if (candidates.empty()) {
            candidates.push_back(root->val);
            helper(root->left, candidates, ans);
            candidates.clear();
            candidates.push_back(root->val);
            helper(root->right, candidates, ans);
        }
        else if (candidates.size() == 1) {
            ans = max(ans, abs(candidates[0] - root->val));
            if (root->val > candidates[0])
                candidates.push_back(root->val);
            else
                candidates.insert(candidates.begin(), root->val);
            tmp1 = candidates[0];
            tmp2 = candidates[1];
            helper(root->left, candidates, ans);
            candidates.clear();
            candidates.push_back(tmp1);
            candidates.push_back(tmp2);
            helper(root->right, candidates, ans);
        }
        else {
            ans = max(ans, abs(candidates[0] - root->val));
            ans = max(ans, abs(candidates[1] - root->val));
            if (root->val < candidates[0])
                candidates[0] = root->val;
            else if (root->val > candidates[1])
                candidates[1] = root->val;
            tmp1 = candidates[0];
            tmp2 = candidates[1];
            helper(root->left, candidates, ans);
            candidates.clear();
            candidates.push_back(tmp1);
            candidates.push_back(tmp2);
            helper(root->right, candidates, ans);
        }
    }
};