#include <stack>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> buffer;
        int op1, op2;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i].length() > 1)
                buffer.push(toInt(tokens[i]));
            else if (tokens[i][0] >= '0' && tokens[i][0] <= '9')
                buffer.push(toInt(tokens[i]));
            else {
                op2 = buffer.top();
                buffer.pop();
                op1 = buffer.top();
                buffer.pop();
                if (tokens[i][0] == '+')
                    op1 += op2;
                else if (tokens[i][0] == '-')
                    op1 -= op2;
                else if (tokens[i][0] == '*')
                    op1 *= op2;
                else
                    op1 /= op2;
                buffer.push(op1);
            }
        }
        return buffer.top();
    }
private:
    int toInt(string num) {
        int index = 0;
        bool negative = false;
        int ans = 0;
        if (num[0] == '-') {
            index = 1;
            negative = true;
        }
        for (; index < num.size(); ++index) {
            ans = ans * 10 + num[index] - '0';
        }
        if (negative)
            ans *= -1;
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};

    cout << s.evalRPN(tokens) << endl;
    return 0;
}