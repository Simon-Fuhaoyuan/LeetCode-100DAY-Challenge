#include <iostream>
#include <queue>
#include <string>
#include <bitset>
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

// HINT: 5 char to store a value, 1 char to store null pointer
// The first char is 0/1/2, indicating null pointer, positive, negative
// For the next 4 char, each char stores 1 byte of origin int
class Codec {

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        queue<TreeNode*> level;
        TreeNode* tmp;
        level.push(root);
        while (!level.empty()) {
            tmp = level.front();
            level.pop();
            if (tmp) {
                data += encode(tmp->val);
                level.push(tmp->left);
                level.push(tmp->right);
            }
            else
                data.push_back(0); // a signing bit for a null pointer
        }
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root, *tmp;
        queue<TreeNode*> level;
        int index = 0;
        if (data[0] == 1)
            return NULL;
        else {
            root = new TreeNode(decode(data.substr(index, 5)));
            level.push(root);
            index += 5;
        }
        while (index < data.length()) {
            tmp = level.front();
            level.pop();
            // tmp->left
            if (data[index] == 0) {
                index++;
                tmp->left = NULL;
            }
            else {
                tmp->left = new TreeNode(decode(data.substr(index, 5)));
                level.push(tmp->left);
                index += 5;
            }
            // tmp->right
            if (data[index] == 0) {
                index++;
                tmp->right = NULL;
            }
            else {
                tmp->right = new TreeNode(decode(data.substr(index, 5)));
                level.push(tmp->right);
                index += 5;
            }
        }
        return root;
    }

private:
    string encode(int val) {
        string ans;
        if (val >= 0)
            ans.push_back(1); // a signing bit for positive
        else {
            ans.push_back(2); // a signing bit for negative
            val *= -1;
        }
        ans.push_back(val >> 24);
        val &= 0x00ffffff;
        ans.push_back(val >> 16);
        val &= 0x0000ffff;
        ans.push_back(val >> 8);
        val &= 0x000000ff;
        ans.push_back(val);
        return ans;
    }

    int decode(string data) {
        int val = 0;
        for (int i = 1; i < 5; ++i) {
            val = val << 8;
            val |= ((int)data[i] & 0x000000ff);
        }
        if (data[0] == 2)
            val *= -1;
        return val;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main() {
    int val = 129;
    string ans;
    ans.push_back(val >> 24);
    val &= 0x00ffffff;
    ans.push_back(val >> 16);
    val &= 0x0000ffff;
    ans.push_back(val >> 8);
    val &= 0x000000ff;
    ans.push_back(val);

    int value = 0;
    for (int i = 0; i < 4; ++i) {
        value = value << 8;
        value |= ((int)ans[i] & 0x000000ff);
    }

    cout << value << endl;
    for (int i = 0; i < 4; ++i)
        cout << (unsigned int)ans[i] << ' ';
    cout << endl;
    return 0;
}