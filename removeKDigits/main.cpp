class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stk;
        int index = 0;
        string ans;
        while (k > 0 && index < num.length()) {
            while (!stk.empty() && stk.top() > num[index] && k > 0) {
                stk.pop();
                k--;
            }
            stk.push(num[index]);
            index++;
        }
        while (k > 0) {
            stk.pop();
            k--;
        }
        ans = num.substr(index);
        while (!stk.empty()) {
            ans.insert(ans.begin(), stk.top());
            stk.pop();
        }

        while (ans.length() > 0 && ans[0] == '0')
            ans.erase(ans.begin());
        if (ans.length() == 0)
            ans = "0";

        return ans;
    }
};
