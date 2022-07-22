#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        vector<ListNode*> all_nodes;
        // Add a virtual head to make the following operations easier
        all_nodes.push_back(new ListNode(0, head));
        
        ListNode* tmp = head;
        while (tmp)
        {
            all_nodes.push_back(tmp);
            tmp = tmp->next;
        }
        all_nodes.push_back(NULL);
        int n = all_nodes.size() - 2;

        int idx1 = k < n - k + 1 ? k : n - k + 1;
        int idx2 = k < n - k + 1 ? n - k + 1 : k;

        if (idx1 == idx2)
            return head;

        if (idx2 - idx1 == 1) // Swap the adjacent nodes
        {
            all_nodes[idx1 - 1]->next = all_nodes[idx2];
            all_nodes[idx2]->next = all_nodes[idx1];
            all_nodes[idx1]->next = all_nodes[idx2 + 1];
        }

        else
        {
            all_nodes[idx1 - 1]->next = all_nodes[idx2];
            all_nodes[idx2]->next = all_nodes[idx1 + 1];
            all_nodes[idx2 - 1]->next = all_nodes[idx1];
            all_nodes[idx1]->next = all_nodes[idx2 + 1];
        }

        return all_nodes[0]->next;
    }
};