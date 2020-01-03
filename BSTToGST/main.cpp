#include <iostream>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct StackNode {
    TreeNode *self;
    bool visited;
    StackNode(TreeNode *node) : self(node), visited(false) {}
};

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root)
    {
        // reverse middle-order traverse from left-mid-right to right-mid-left
        stack<StackNode*> stk;
        StackNode* tmp = new StackNode(root);
        int sum = 0;
        stk.push(tmp);
        while(!stk.empty())
        {
            tmp = stk.top();
            if (tmp->visited)
            {
                stk.pop();
                sum += tmp->self->val;
                tmp->self->val = sum;
                if (tmp->self->left != NULL)
                    stk.push(new StackNode(tmp->self->left));
            }
            else
            {
                if (tmp->self->right != NULL)
                    stk.push(new StackNode(tmp->self->right));
                tmp->visited = true;
            }
        }
        
        return root;
    }
};