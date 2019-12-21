#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        string::iterator it = s.begin();
        while(it != s.end())
        {
            if (*it == '(' || *it == '[' || *it == '{')
                stk.push(*it);
            else
            {
                if (stk.empty()) return false;
                if ((*it == ')' && stk.top() == '(') || 
                    (*it == '}' && stk.top() == '{') || 
                    (*it == ']' && stk.top() == '['))
                    stk.pop();
                else
                    return false;
            }
            it++;
        }
        if (stk.empty()) return true;
        return false;
    }
};

int main()
{
    Solution s;
    string str = "]";
    cout << s.isValid(str) << endl;
    return 0;
}