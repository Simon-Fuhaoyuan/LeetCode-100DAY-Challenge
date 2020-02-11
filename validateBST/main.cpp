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
    // According to defination, the mid-order traverse of a valid BST is increasing order.
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        vector<int> order;
        midOrder(root, order);
        for (int i = 0; i < order.size() - 1; ++i) {
            if (order[i] >= order[i + 1])
                return false;
        }
        return true;
    }
private:
    void midOrder(TreeNode *root, vector<int> &order) {
        if (root == NULL)
            return;
        midOrder(root->left, order);
        order.push_back(root->val);
        midOrder(root->right, order);
    }
};

int main() {

}