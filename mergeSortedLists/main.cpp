#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL || l2 == NULL)
        {
            if (l1 != NULL) return l1;
            else if (l2 != NULL) return l2;
            else return NULL;
        }
        ListNode *ans;
        ListNode *tmp;
        if (l1->val < l2->val)
        {
            ans = new ListNode(l1->val);
            l1 = l1->next;
        }
        else
        {
            ans = new ListNode(l2->val);
            l2 = l2->next;
        }
        tmp = ans;
        while(l1 != NULL && l2 != NULL)
        {
            tmp->next = new ListNode(0);
            tmp = tmp->next;
            if (l1->val < l2->val)
            {
                tmp->val = l1->val;
                l1 = l1->next;
            }
            else
            {
                tmp->val = l2->val;
                l2 = l2->next;
            }
        }
        while (l1 != NULL)
        {
            tmp->next = new ListNode(0);
            tmp = tmp->next;
            tmp->val = l1->val;
            l1 = l1->next;
        }
        while (l2 != NULL)
        {
            tmp->next = new ListNode(0);
            tmp = tmp->next;
            tmp->val = l2->val;
            l2 = l2->next;
        }
        
        return ans;
    }
};