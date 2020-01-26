#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/**
 Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = new TreeNode(preorder[0]);
        TreeNode *curr = root;
        stack<TreeNode*> stk;
        stk.push(root);
        for (int i = 1; i < preorder.size(); ++i) {
            if (curr->val > preorder[i]) {
                curr->left = new TreeNode(preorder[i]);
                stk.push(curr);
                curr = curr->left;
            }
            else {
                while (!stk.empty() && stk.top()->val < preorder[i]) {
                    curr = stk.top();
                    stk.pop();
                }
                curr->right = new TreeNode(preorder[i]);
                curr = curr->right;
            }
        }
        return root;
    }
};

int main() {
    Solution s;
    vector<int> preorder({8,5,1,7,10,12});
    TreeNode* root = s.bstFromPreorder(preorder);
    queue<TreeNode*> que;
    que.push(root);
    TreeNode *curr;
    while (!que.empty()) {
        curr = que.front();
        que.pop();
        if (curr == NULL)
            cout << "null" << ' ';
        else {
            cout << curr->val << ' ';
            if (curr->left != NULL || curr->right != NULL) {
                que.push(curr->left);
                que.push(curr->right);
            }
        }
    }
    return 0;
}