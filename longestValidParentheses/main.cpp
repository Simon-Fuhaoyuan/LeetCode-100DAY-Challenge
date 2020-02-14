#include <iostream>
#include <string>
#include <stack>
using namespace std;

// my stupid solution
class Solution1 {
public:
    int longestValidParentheses(string s) {
        int length = s.length();
        int *dp = new int[length + 1];
        dp[length] = 0;
        int stack = 0, idx;
        int max = 0;
        // dp for search
        for (int i = length - 1; i >= 0; --i) {
            stack = 0;
            if (s[i] == ')')
                dp[i] = 0;
            else {
                idx = i + 1;
                stack++;
                while (stack > 0 && idx < length) {
                    if (dp[idx]) {
                        idx += dp[idx];
                        continue;
                    }
                    if (s[idx] == ')')
                        stack--;
                    else
                        stack++;
                    idx++;
                }
                if (stack != 0)
                    dp[i] = 0;
                else {
                    dp[i] = idx - i + dp[idx];
                    if (dp[i] > max)
                        max = dp[i];
                }
            }
        }
        
        return max;
    }
};

// record the start position of a possible valid parentheses
// use a stack to record each '(' position
class Solution2 {
public:
    int longestValidParentheses(string s) {
        int res = 0, start = 0, n = s.size();
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') st.push(i);
            else if (s[i] == ')') {
                if (st.empty()) start = i + 1;
                else {
                    st.pop();
                    res = st.empty() ? max(res, i - start + 1) : max(res, i - st.top());
                    // if stack is not empty, the valid parentheses must exist between i and st.top() + 1
                }
            }
        }
        return res;
    }
};

// no need for extra space
// record number of '(' and ')' (left and right), if right > left, this is invalid
// but there's another problem, when str is like '(()', until the end of the string, left cannot be equal to right
// so we need to check from last to start, and this solves.
class Solution3 {
public:
    int longestValidParentheses(string s) {
        int res = 0, left = 0, right = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            (s[i] == '(') ? ++left : ++right;
            if (left == right) res = max(res, 2 * right);
            else if (right > left) left = right = 0;
        }
        left = right = 0;
        for (int i = n - 1; i >= 0; --i) {
            (s[i] == '(') ? ++left : ++right;
            if (left == right) res = max(res, 2 * left);
            else if (left > right) left = right = 0;
        }
        return res;
    }
};

int main() {
    Solution1 s;
    cout << s.longestValidParentheses("((()()))())") << endl;
    return 0;
}