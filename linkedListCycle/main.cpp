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

/**
 * HINT: Use two pointers, p1 and p2.
 * p1 goes 1 step each time.
 * p2 goes 2 steps each time.
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p1 = head, *p2 = head;
        do {
            if (p1 && p1->next)
                p1 = p1->next;
            else
                return false;
            if (p2 && p2->next && p2->next->next)
                p2 = p2->next->next;
            else
                return false;
        } while (p1 != p2);
        return true;
    }
};