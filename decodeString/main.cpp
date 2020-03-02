#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string ans;
        int idx = 0;
        int times;
        int start, accu;
        while (idx < s.length()) {
            if (s[idx] >= '0' && s[idx] <= '9') {
                times = 0;
                while (s[idx] != '[') {
                    times = times * 10 + s[idx] - '0';
                    idx++;
                }
                idx++;
                accu = 1;
                start = idx;
                while (accu != 0) {
                    if (s[idx] == '[')
                        accu++;
                    else if (s[idx] == ']')
                        accu--;
                    idx++;
                }
                string part = decodeString(s.substr(start, idx - start - 1));
                for (int i = 0; i < times; ++i)
                    ans += part;
            }
            else {
                ans.push_back(s[idx]);
                idx++;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    string str = "2[abc]3[cd]ef";
    cout << s.decodeString(str) << endl;
    return 0;
}