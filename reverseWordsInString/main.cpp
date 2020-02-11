#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int length = s.length();
        int index = 0;
        int start = 0;
        string word;
        while (index < length) {
            while (index < length && s[index] == ' ')
                index++;
            if (index >= length)
                break;
            // start of a word
            start = index;
            while (index < length && s[index] != ' ')
                index++;
            word = s.substr(start, index - start);
            if (ans.length())
                word.push_back(' ');
            ans = word + ans;
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.reverseWords("  hello world!  ") << endl;
    return 0;
}