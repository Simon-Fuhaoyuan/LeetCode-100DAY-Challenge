#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct Func {
	bool operator() (ListNode *a, ListNode *b) {
		return a->val > b->val;
	}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int k = lists.size();
		if (k == 0)
			return NULL;
		if (k == 1)
			return lists[0];

		ListNode *ans, *tmp, *curr;
		priority_queue<ListNode*, vector<ListNode*>, Func> heap;
		for (int i = 0; i < k; ++i)
			if (lists[i] != NULL)
				heap.push(lists[i]);
		// the very first element
		if (!heap.empty()) {
			curr = heap.top();
			heap.pop();
			ans = curr;
			if (curr->next != NULL)
				heap.push(curr->next);
		}
		else
			return NULL;
		tmp = ans;
		while (!heap.empty()) {
			curr = heap.top();
			heap.pop();
			tmp->next = curr;
			tmp = curr;
			if (curr->next != NULL)
				heap.push(curr->next);
		}
		return ans;
	}
};
