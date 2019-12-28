#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct StackNode {
    TreeNode *self;
    int times;
    StackNode(TreeNode *s, int t) : self(s), times(t) {}
    StackNode() : self(NULL), times(0) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root)
    {
        // middle-order traverse
        stack<StackNode*> tree;
        vector<StackNode*> post_order;
        StackNode *tmp;
        tmp = new StackNode(root, 0);
        tree.push(tmp);
        while(!tree.empty())
        {
            tmp = tree.top();
            if (tmp->times == 0)
            {
                tmp->times++;
                
                if (tmp->self->left != NULL)
                {
                    tmp = new StackNode(tmp->self->left, 0);
                    tree.push(tmp);
                }
            }
            else
            {
                tree.pop();
                post_order.push_back(tmp);
                if (tmp->self->right != NULL)
                {
                    tmp = new StackNode(tmp->self->right, 0);
                    tree.push(tmp);
                }
            }
        }
        // check the post-order consequenceand find the swap
        StackNode *swap1, *swap2;
        bool flag = false; // whether the first swap appears
        for (int i = 0; i < post_order.size() - 1; ++i)
            if (post_order[i]->self->val > post_order[i + 1]->self->val)
            {
                if (!flag)
                {
                    swap1 = post_order[i];
                    swap2 = post_order[i + 1];
                    flag = true;
                }
                else
                {
                    swap2 = post_order[i + 1];
                    break;
                }
            }
        // swap two treeNodes
        int TMP = swap1->self->val;
        swap1->self->val = swap2->self->val;
        swap2->self->val = TMP;
    }
};

void levelOrder(TreeNode *root)
{
    queue<TreeNode*> que;
    TreeNode *tmp;
    que.push(root);
    while (!que.empty())
    {
        tmp = que.front();
        que.pop();
        if (tmp == NULL)
            cout << "null ";
        else
        {
            cout << tmp->val <<' ';
            que.push(tmp->left);
            que.push(tmp->right);
        }
    }
    cout << endl;
}

int main()
{
    TreeNode *root;
    vector<int> arr;
    Solution s;

    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(0);
    arr.push_back(0);
    arr.push_back(2);

    queue<TreeNode*> level;
    TreeNode* tmp;
    root = new TreeNode(arr[0]);
    level.push(root);
    int times = 0;
    for (int i = 1; i < arr.size(); ++i)
    {
        if (times == 0)
        {
            times++;
            if (arr[i] != 0)
            {
                tmp = new TreeNode(arr[i]);
                level.push(tmp);
                level.front()->left = tmp;
            }
        }
        else if (times == 1)
        {
            times = 0;
            if (arr[i] != 0)
            {
                tmp = new TreeNode(arr[i]);
                level.push(tmp);
                level.front()->right = tmp;
            }
            level.pop();
        }
    }
    // constructTree(arr, root);
    // levelOrder(root);

    s.recoverTree(root);
    levelOrder(root);

    return 0;
}