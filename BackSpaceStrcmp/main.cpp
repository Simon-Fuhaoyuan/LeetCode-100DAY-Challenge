#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        dealStr(S);
        dealStr(T);
        return S == T;
    }

private:
    void dealStr(string &str) {
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == '#') {
                if (i == 0) {
                    str.erase(str.begin());
                    i--;
                }
                else {
                    str.erase(str.begin() + i);
                    str.erase(str.begin() + i - 1);
                    i -= 2;
                }
            }
        }
    }
};

int main() {
    Solution s;
    string S = "ab#c";
    string T = "ad#c";

    cout << s.backspaceCompare(S, T) << endl;
    return 0;
}