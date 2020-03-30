#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int length = popped.size();
        int idx_pop = 0, idx_pus = 0;
        while (idx_pop < length) {
            while (idx_pus < length && (stk.empty() || stk.top() != popped[idx_pop]))
                stk.push(pushed[idx_pus++]);
            if (stk.top() != popped[idx_pop])
                return false;
            stk.pop();
            idx_pop++;
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> pushed({1,2,3,4,5});
    vector<int> popped({4,5,3,1,2});
    cout << s.validateStackSequences(pushed, popped) << endl;
    return 0;
}