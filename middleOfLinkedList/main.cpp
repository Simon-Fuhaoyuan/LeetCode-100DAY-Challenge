#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* quick = head;
        ListNode* slow = head;
        while (quick->next) {
            slow = slow->next;
            quick = quick->next;
            if (quick->next)
                quick = quick->next;
        }
        return slow;
    }
};