#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int buffer = 0;
        int star_cnt = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                buffer++;
            else if (s[i] == '*')
                star_cnt++;
            else
                buffer--;
            if (buffer < 0) {
                if (star_cnt > 0) {
                    star_cnt--;
                    buffer++;
                }
                else
                    return false;
            }
        }
        if (buffer == 0)
            return true;
        if (star_cnt < buffer)
            return false;

        // cout << "ok" << endl;
        buffer = 0;
        star_cnt = 0;

        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == ')')
                buffer++;
            else if (s[i] == '*')
                star_cnt++;
            else
                buffer--;
            if (buffer < 0) {
                if (star_cnt > 0) {
                    star_cnt--;
                    buffer++;
                }
                else
                    return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    string str = "(())((())()()(*)(*()(())())())()()((()())((()))(*";
    cout << s.checkValidString(str) << endl;
    return 0;
}