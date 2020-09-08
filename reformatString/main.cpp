#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    string reformat(string s) {
        string ans;
        int length = s.length();
        queue<char> letters;
        queue<char> digits;
        queue<char>* first;
        queue<char>* second;
        for (int i = 0; i < length; ++i) {
            if (s[i] >= '0' && s[i] <= '9')
                digits.push(s[i]);
            else
                letters.push(s[i]);
        }

        if (letters.size() >= digits.size()) {
            first = &letters;
            second = &digits;
        }
        else {
            first = &digits;
            second = &letters;
        }

        if (first->size() - second->size() > 1) {
            return "";
        }

        while (!first->empty()) {
            ans.push_back(first->front());
            first->pop();
            if (!second->empty()) {
                ans.push_back(second->front());
                second->pop();
            }
        }
        
        return ans;
    }
};

int main() {
    Solution s;
    string str = "covid2019";

    cout << s.reformat(str) << endl;
    return 0;
}