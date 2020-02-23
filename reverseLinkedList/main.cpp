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

// iteratively
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return head;
        ListNode *new_head = head;
        ListNode *tmp = head->next;
        head->next = NULL;
        while (tmp) {
            new_head = tmp;
            tmp = tmp->next;
            new_head->next = head;
            head = new_head;
        }
        return head;
    }
};

// recursively
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return head;
        ListNode* tail = rec_reverse(head);
        tail->next = NULL;
        return head;
    }
private:
    // Note return is the tail node
    ListNode* rec_reverse(ListNode* &head) {
        if (!head->next)
            return head;
        ListNode *tail = rec_reverse(head->next);
        tail->next = head;
        tail = head;
        head = head->next;
        return tail;
    }
};