#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return NULL;
        vector<Node*> nodes;
        unordered_map<Node*, int> random;
        // deal with head node
        int cnt = 0;
        Node *new_head;
        new_head = new Node(head->val);
        nodes.push_back(new_head);
        random.insert(make_pair(head, cnt++));
        Node *new_tmp = new_head, *tmp = head;
        // construct the linked list and store each index with address
        while (tmp->next) {
            tmp = tmp->next;
            new_tmp->next = new Node(tmp->val);
            new_tmp = new_tmp->next;
            nodes.push_back(new_tmp);
            random.insert(make_pair(tmp, cnt++));
        }
        // add random info
        new_tmp = new_head;
        tmp = head;
        while (tmp) {
            if (!tmp->random)
                new_tmp->random = NULL;
            else
                new_tmp->random = nodes[random[tmp->random]];
            tmp = tmp->next;
            new_tmp = new_tmp->next;
        }
        return new_head;
    }
};