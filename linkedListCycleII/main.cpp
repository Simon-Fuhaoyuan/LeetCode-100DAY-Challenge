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
 * HINT: use the same way in LinkedListCycle to detect cycle.
 * Assume the number of nodes before the starting node is x.
 * The number of nodes in cycle is N.
 * As the p2 goes 1 nodes quicker than p1 each time, when they
 * meet, p2 goes N nodes more than p1. That is, p1 goes N, and 
 * p2 goes 2N.
 * As the number of extra nodes before the starting of cycle is x,
 * we know that p1 goes N-x nodes after going into the cycle, which
 * means p1 need x more steps to finish the cycle.
 * So, if we let p1 and a new pointer p3(from the start) goes together,
 * they will meet just at the starting point of the cycle.
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *p1 = head, *p2 = head;
        do {
            if (p1 && p1->next)
                p1 = p1->next;
            else
                return NULL;
            if (p2 && p2->next && p2->next->next)
                p2 = p2->next->next;
            else
                return NULL;
        } while (p1 != p2);
        // Until here, we can say there exists the cycle
        p1 = head;
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};