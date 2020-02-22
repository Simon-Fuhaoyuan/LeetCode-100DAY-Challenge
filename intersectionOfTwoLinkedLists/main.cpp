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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cnt_A = 0, cnt_B = 0;
        ListNode *tmp;
        // get the length of linked list A and B
        tmp = headA;
        while (tmp) {
            tmp = tmp->next;
            cnt_A++;
        }
        tmp = headB;
        while (tmp) {
            tmp = tmp->next;
            cnt_B++;
        }
        // the longer linked list goes a few steps first to keep equal
        if (cnt_A > cnt_B) {
            for (int i = 0; i < cnt_A - cnt_B; ++i)
                headA = headA->next;
        }
        else {
            for (int i = 0; i < cnt_B - cnt_A; ++i)
                headB = headB->next;
        }
        // two linked list is the same length, so if they have
        // intersection, they must reach together
        while (headA && headB) {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};