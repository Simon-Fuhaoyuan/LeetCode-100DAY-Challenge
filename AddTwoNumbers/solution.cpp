#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int carry = 0;
        int val = 0;
        ListNode* ans = NULL;
        ListNode* tmp = ans;
        while(l1 != NULL && l2 != NULL)
        {
            val = l1->val + l2->val + carry;

            if (val > 9)
            {
                val -= 10;
                carry = 1;
            }
            else carry = 0;

            if (ans == NULL)
            {
                ans = new ListNode(val);
                tmp = ans;
            }
            else
            {
                tmp->next = new ListNode(val);
                tmp = tmp->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1 != NULL)
        {
            while(l1 != NULL)
            {
                val = l1->val + carry;

                if (val > 9)
                {
                    val -= 10;
                    carry = 1;
                }
                else carry = 0;

                ans->next = new ListNode(val);
                ans = ans->next;
                l1 = l1->next;
            }
        }
        else if (l2 != NULL)
        {
            while(l2 != NULL)
            {
                val = l2->val + carry;

                if (val > 9)
                {
                    val -= 10;
                    carry = 1;
                }
                else carry = 0;

                ans->next = new ListNode(val);
                ans = ans->next;
                l2 = l2->next;
            }
        }
        
        if (carry != 0)
        {
            tmp->next = new ListNode(carry);
            tmp = tmp->next;
        }
        
        return ans;
    }
};