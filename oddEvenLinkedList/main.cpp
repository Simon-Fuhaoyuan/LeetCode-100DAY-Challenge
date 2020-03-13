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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !(head->next) || !(head->next->next))
            return head;
        ListNode* back_head = head->next;
        ListNode* tmp = head->next->next;
        ListNode* front_tmp = head, *back_tmp = back_head;
        while (tmp) {
            front_tmp->next = tmp;
            tmp = tmp->next;
            front_tmp = front_tmp->next;
            if (!tmp)
                break;
            back_tmp->next = tmp;
            tmp = tmp->next;
            back_tmp = back_tmp->next;
        }
        back_tmp->next = NULL;
        front_tmp->next = back_head;
        return head;
    }
};