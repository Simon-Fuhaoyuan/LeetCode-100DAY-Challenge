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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) return NULL;
        ListNode *pre = head, *post = head;
        for (int i = 0; i < n; ++i)
            post = post->next;
        if (!post)
            return head->next;
        while (post->next) {
            post = post->next;
            pre = pre->next;
        }
        pre->next = pre->next->next;
        return head;
    }
};

int main() {

}