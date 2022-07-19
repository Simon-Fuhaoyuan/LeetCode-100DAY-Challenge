#include <iostream>
#include <vector>
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
private:
    vector<int> ans;
    void distanceKHelper(TreeNode* node, int left_dist)
    {
        if (left_dist < 0)
            return;
        if (left_dist == 0)
        {
            ans.push_back(node->val);
            return;
        }
        if (node->left)
            distanceKHelper(node->left, left_dist - 1);
        if (node->right)
            distanceKHelper(node->right, left_dist - 1);
    }

    bool DFSForTarget(TreeNode* node, TreeNode* target, stack<TreeNode*> &trajectory)
    {
        if (node == NULL)
            return false;

        trajectory.push(node);
        
        if (node->val == target->val || DFSForTarget(node->left, target, trajectory) || DFSForTarget(node->right, target, trajectory))
            return true;

        trajectory.pop();
        return false;
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        ans = vector<int>();

        // Find the trajectory from root to target
        stack<TreeNode*> trajectory = stack<TreeNode*>();
        DFSForTarget(root, target, trajectory);

        // Find distance k nodes from target
        distanceKHelper(trajectory.top(), k);

        // For ancestors of target, find the left distance to target
        TreeNode* child = trajectory.top();
        TreeNode* parent;
        trajectory.pop();
        while (!trajectory.empty() && k > 0)
        {
            parent = trajectory.top();
            k -= 1;

            // If the ancestor's distance to target is k (i.e., k is minus to 0), 
            // the ancestor will be assigned to answer and no other paths from this ancestor is valid.
            if (k == 0)
            {
                ans.push_back(parent->val);
                break;
            }
            if (child == parent->left && parent->right)
                distanceKHelper(parent->right, k - 1);
            else if (child == parent->right && parent->left)
                distanceKHelper(parent->left, k - 1);
            
            child = parent;
            trajectory.pop();
        }

        return ans;
    }
};
