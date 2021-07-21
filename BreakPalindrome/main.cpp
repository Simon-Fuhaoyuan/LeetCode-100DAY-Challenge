#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int length = palindrome.size() / 2;
        if (length == 0) {
            return "";
        }

        for (int i = 0; i < length; ++i) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }

        palindrome[palindrome.size() - 1] = 'b';
        return palindrome;
    }
};

int main() {
    Solution s;
    cout << s.breakPalindrome("abcba") << endl;
}
