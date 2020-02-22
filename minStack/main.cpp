#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> stk;
    stack<int> min_ele;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        stk.push(x);
        if (min_ele.empty() || x <= min_ele.top())
            min_ele.push(x);
    }
    
    void pop() {
        if (stk.top() == min_ele.top()) {
            min_ele.pop();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_ele.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */