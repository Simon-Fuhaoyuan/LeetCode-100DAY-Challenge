#include <string>
#include <iostream>
using namespace std;

// This code is really ugly!!!!!!!

class Solution {
public:
    bool isMatch(string s, string p) {
        // simplify the pattern
        for (int i = 0; i < p.length(); ++i) {
            // if muliple "x*" connecting together, we just preserve one
            if (p[i] == '*') {
                while (i + 2 < p.length() && p[i + 2] == '*' && p[i - 1] == p[i + 1]) {
                    p.erase(p.begin() + i + 1);
                    p.erase(p.begin() + i + 1);
                }
            }
            // if exist a ".*", all "x*" after it lose their powers
            else if (i + 1 < p.length() && p[i] == '.' && p[i + 1] == '*') {
                while (i + 3 < p.length() && p[i + 3] == '*') {
                    p.erase(p.begin() + i + 2);
                    p.erase(p.begin() + i + 2);
                }
            }
        }
        // cout << p << endl;
        return isMatch(s, p, true); // the third parameter is for distinguish
    }
private:
    bool isMatch(string s, string p, bool flag) {
        int index_s = 0;
        int index_p = 0;
        int length_s = s.length();
        int length_p = p.length();
        char repeat;
        while (index_s < length_s && index_p < length_p) {
            if (s[index_s] == p[index_p]) { // equal
                // cout << "equal " << index_s << index_p << endl;
                if (index_p + 1 >= length_p || p[index_p + 1] != '*') // "x*" may not be used
                    index_s++;
                index_p++;
                continue;
            }
            // not equal
            // two different letters, check if exists '*'
            if (p[index_p] >= 'a' && p[index_p] <= 'z') {
                // cout << "not equal " << index_s << index_p << endl;
                if (index_p + 1 < length_p && p[index_p + 1] == '*') {
                    index_p += 2;
                    continue;
                }
                else {
                    return false;
                }
            }
            // p is '.'
            if (p[index_p] == '.') {
                // cout << ". " << index_s << index_p << endl;
                if (index_p + 1 < length_p && p[index_p + 1] == '*') { // ".*"
                    index_p += 2;
                    if (index_p == length_p) // ".*" at the end of pattern, must be true
                        return true;
                    while (index_s < length_s) {
                        if (isMatch(s.substr(index_s), p.substr(index_p), true))
                            return true;
                        index_s++;
                    }
                    return false;
                }
                else {
                    index_p++;
                    index_s++;
                    continue;
                }
            }
            // p is '*'
            if (p[index_p] == '*') {
                // cout << "* " << index_s << index_p << endl;
                repeat = p[index_p - 1];
                index_p++;
                while (index_s < length_s && s[index_s] == repeat) {
                    if (isMatch(s.substr(index_s), p.substr(index_p), true))
                        return true;
                    index_s++;
                }
                if (isMatch(s.substr(index_s), p.substr(index_p), true))
                    return true;
                return false;
            }
        }

        if (index_s == length_s && index_p == length_p)
            return true;
        else if (index_s != length_s)
            return false;
        else {
            while (index_p < length_p) {
                if (p[index_p] == '*') {
                    index_p++;
                    continue;
                }
                else if (index_p + 1 < length_p && p[index_p + 1] == '*') {
                    index_p += 2;
                    continue;
                }
                else
                    break;
            }
            if (index_p == length_p)
                return true;
            else 
                return false;
        }
    }
};

int main() {
    Solution S;

    string s = "abcaaaaaaabaabcabac";
    string p = ".*ab.a.*a*a*.*b*b*";
    cout << S.isMatch(s, p) << endl;

    return 0;
}