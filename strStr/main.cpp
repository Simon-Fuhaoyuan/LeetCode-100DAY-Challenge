#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) return 0;
        if (haystack.length() < needle.length()) return -1;
        int j = 0;
        for (int i = 0; i <= haystack.length() - needle.length(); ++i) {
            if (haystack[i] == needle[0]) {
                for (j = 1; j < needle.length(); ++j) {
                    if (haystack[i + j] != needle[j])
                        break;
                }
                if (j == needle.length())
                    return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    cout << s.strStr("hello", "ll") << endl;

    return 0;
}