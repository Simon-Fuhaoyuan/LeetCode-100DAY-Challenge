#include <iostream>
#include "solution.cpp"

using namespace std;

void getList(ListNode *l, int *arr, int size);
void print(ListNode *l);

int main()
{
    ListNode *l1, *l2;
    int a[3] = {2, 4, 3};
    int b[3] = {5, 6, 4};
    getList(l1, a, 3);
    getList(l2, b, 3);

    Solution s;
    ListNode *ans;
    ans = s.addTwoNumbers(l1, l2);

    print(ans);

    return 0;
}

void getList(ListNode *l, int *arr, int size)
{
    
}