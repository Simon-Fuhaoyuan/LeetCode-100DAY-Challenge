#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                cnt1++;
            else if (s[i] == ')') {
                if (cnt1 > 0)
                    cnt1--;
                else
                    cnt2++;
            }
        }
        helper(s, 0, cnt1, cnt2, ans);
        return ans;
    }
private:
    void helper(string s, int start, int cnt1, int cnt2, vector<string>& ans) {
        if (cnt1 == 0 && cnt2 == 0) {
            if (isValid(s))
                ans.push_back(s);
            return;
        }
        for (int i = start; i < s.length(); ++i) {
            if (i != start && s[i] == s[i - 1])
                continue;
            if (cnt1 > 0 && s[i] == '(') {
                helper(s.substr(0, i) + s.substr(i + 1), i, cnt1 - 1, cnt2, ans);
            }
            else if (cnt2 > 0 && s[i] == ')') {
                helper(s.substr(0, i) + s.substr(i + 1), i, cnt1, cnt2 - 1, ans);
            }
        }
    }

    bool isValid(string s) {
        int state = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                state++;
            else if (s[i] == ')' && --state < 0)
                return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    string str = ")()((";
    vector<string> ans = s.removeInvalidParentheses(str);
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << endl;
    return 0;
}