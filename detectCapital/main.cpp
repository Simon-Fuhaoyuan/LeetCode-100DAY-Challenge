#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        bool Lower = true;
        if (word[0] <= 'Z' && word[0] >= 'A') {
            if (word.length() == 1) return true;
            if (word[1] <= 'Z' && word[1] >= 'A')
                Lower = false;
        }
        if (Lower) {
            for (int i = 1; i < word.length(); ++i)
                if (word[i] < 'a' || word[i] > 'z')
                    return false;
            return true;
        }
        else
        {
            for (int i = 2; i < word.length(); ++i)
                if (word[i] < 'A' || word[i] > 'Z')
                    return false;
            return true;
        }
    }
};

int main() {
    Solution s;
    cout << s.detectCapitalUse("GooglE") << endl;

    return 0;
}