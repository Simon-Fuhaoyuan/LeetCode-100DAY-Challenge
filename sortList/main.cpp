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

// Merge sort
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head)
            return NULL;
        int cnt = 0;
        ListNode* tmp = head;
        while (tmp) {
            cnt++;
            tmp = tmp->next;
        }
        mergeSort(head, cnt);
        return head;
    }
private:
    void mergeSort(ListNode *&head, int cnt) {
        if (cnt == 1) {
            head->next = NULL;
            return;
        }

        int left_cnt = cnt / 2, right_cnt = cnt - left_cnt;
        ListNode *left = head, *right = head, *tmp;
        for (int i = 0; i < left_cnt; ++i)
            right = right->next;
        mergeSort(left, left_cnt);
        mergeSort(right, right_cnt);
        
        if (left->val < right->val) {
            head = left;
            left = left->next;
        }
        else {
            head = right;
            right = right->next;
        }
        tmp = head;
        while (left && right) {
            if (left->val < right->val) {
                tmp->next = left;
                left = left->next;
                tmp = tmp->next;
            }
            else {
                tmp->next = right;
                right = right->next;
                tmp = tmp->next;
            }
        }
        if (!left)
            tmp->next = right;
        else if (!right)
            tmp->next = left;
    }
};

int main() {
    ListNode *head = new ListNode(-1);
    ListNode *tmp = head;
    tmp->next = new ListNode(5); tmp = tmp->next;
    tmp->next = new ListNode(3); tmp = tmp->next;
    tmp->next = new ListNode(4); tmp = tmp->next;
    tmp->next = new ListNode(0); tmp = tmp->next;

    cout << "Input: ";
    tmp = head;
    while (tmp) {
        cout << tmp->val << ' ';
        tmp = tmp->next;
    }
    cout << endl;

    Solution s;
    head = s.sortList(head);
    cout << "Output: ";
    tmp = head;
    while (tmp) {
        cout << tmp->val << ' ';
        tmp = tmp->next;
    }
    cout << endl;
}