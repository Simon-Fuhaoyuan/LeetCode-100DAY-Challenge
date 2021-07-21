#include <iostream>
#include <queue>
#include <stack>
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

class FindElements {
private:
    TreeNode* root;
public:
    FindElements(TreeNode* root) {
        this->root = root;
        // RecoverElementsBFS();
        RecoverElementsDFS();
    }

    void RecoverElementsBFS() {
        root->val = 0;
        queue<TreeNode*> que;
        TreeNode* tmp;
        que.push(root);
        while (!que.empty()) {
            tmp = que.front();
            que.pop();
            if (tmp->left != nullptr) {
                tmp->left->val = tmp->val * 2 + 1;
                que.push(tmp->left);
            }
            if (tmp->right != nullptr) {
                tmp->right->val = tmp->val * 2 + 2;
                que.push(tmp->right);
            }
        }
    }

    void RecoverElementsDFS() {
        root->val = 0;
        stack<TreeNode*> sta;
        TreeNode* tmp;
        sta.push(root);
        while (!sta.empty()) {
            tmp = sta.top();
            sta.pop();
            if (tmp->left != nullptr) {
                tmp->left->val = tmp->val * 2 + 1;
                sta.push(tmp->left);
            }
            if (tmp->right != nullptr) {
                tmp->right->val = tmp->val * 2 + 2;
                sta.push(tmp->right);
            }
        }
    }
    
    bool find(int target) {
        stack<int> sta;
        while (target != 0) {
            sta.push(target);
            target = (target - 1) / 2;
        }
        // sta.pop(); // Pop element 0.

        int curr_target;
        TreeNode* tmp = root;
        while (!sta.empty()) {
            curr_target = sta.top();
            sta.pop();
            if (curr_target == tmp->val * 2 + 1) {
                tmp = tmp->left;
            }
            else if (curr_target == tmp->val * 2 + 2) {
                tmp = tmp->right;
            }
            if (tmp == nullptr)
                return false;
        }

        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */