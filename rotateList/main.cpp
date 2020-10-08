#include <iostream>
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return head;
        int length = 0;
        ListNode* tmp = head;
        while (tmp) {
            tmp = tmp->next;
            length++;
        }

        k %= length;
        if (k == 0)
            return head;

        ListNode* new_head = head;
        for (int i = 0; i < length - k - 1; ++i)
            new_head = new_head->next;
        ListNode* new_tail = new_head;
        new_head = new_head->next;
        new_tail->next = NULL;
        
        tmp = new_head;
        for (int i = 0; i < k - 1; ++i)
            tmp = tmp->next;
        tmp->next = head;

        return new_head;
    }
};