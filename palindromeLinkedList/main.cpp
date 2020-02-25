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
    bool isPalindrome(ListNode* head) {
        // get the length of linked list
        ListNode *tmp = head;
        int length = 0;
        while (tmp) {
            length++;
            tmp = tmp->next;
        }
        if (length == 1)
            return true;
        // reverse the first half of the linked list
        // remember to deal with odd and even
        bool odd = (length % 2 > 0);
        length /= 2;
        ListNode* new_head = head->next;
        head->next = NULL;
        for (int i = 1; i < length; ++i) {
            tmp = new_head->next;
            new_head->next = head;
            head = new_head;
            new_head = tmp;
        }
        if (odd) // for odd length, skip the middle one
            new_head = new_head->next;
        // compare this half linked list
        while (head) {
            if (head->val != new_head->val)
                return false;
            head = head->next;
            new_head = new_head->next;
        }
        return true;
    }
};