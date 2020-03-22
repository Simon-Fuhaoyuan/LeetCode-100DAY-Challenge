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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1)
            return head;
        ListNode *lastTail = NULL;
        ListNode *thisHead = head, *thisTail, *tmp;
        bool flag;
        while (true) {
            flag = true;
            tmp = thisHead;
            for (int i = 0; i < k; ++i) {
                if (tmp) {
                    thisTail = tmp;
                    tmp = tmp->next;
                }
                else {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;
            helper(thisHead, thisTail);
            if (lastTail == NULL)
                head = thisHead;
            else
                lastTail->next = thisHead;
            thisHead = tmp;
            thisTail->next = tmp;
            lastTail = thisTail;
        }
        return head;
    }
private:
    void helper(ListNode* &head, ListNode* &tail) {
        ListNode* tmp = head->next, *nextNode, *lastNode = head;
        ListNode* end = tail->next;
        while (tmp != end) {
            nextNode = tmp->next;
            tmp->next = lastNode;
            lastNode = tmp;
            tmp = nextNode;
        }
        tmp = head;
        head = tail;
        tail = tmp;
    }
};