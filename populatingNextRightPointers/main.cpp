#include <iostream>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return root;
        int level = 1;
        int cnt = 2;
        Node *left, *right;
        bool flag;
        while (true) {
            left = root;
            flag = true;
            for (int i = 0; i < level; ++i) {
                if (left->left == NULL) {
                    flag = false;
                    break;
                }
                left = left->left;
            }
            if (!flag)
                break;
            for (int i = 1; i < cnt; ++i) {
                right = decode(root, level, i);
                left->next = right;
                left = right;
            }
            level *= 2;
            cnt *= 2;
        }
        return root;
    }
private:
    Node* decode(Node* root, int level, int code) {
        int mask = 1 << (level - 1);
        for (int i = 0; i < level; ++i) {
            if ((code & mask) == 0)
                root = root->left;
            else
                root = root->right;
            mask = mask >> 1;
        }
        return root;
    }
};