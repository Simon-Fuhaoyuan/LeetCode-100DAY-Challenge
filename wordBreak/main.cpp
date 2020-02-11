#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (int i = 0; i < wordDict.size(); ++i)
            dict.insert(wordDict[i]);
        int length = s.length();
        bool *dp = new bool[length + 1];
        dp[length] = true;
        for (int i = length - 1; i >= 0; --i) {
            dp[i] = wordBreak(s.substr(i), dict, dp + i);
        }
        return dp[0];
    }
private:
    bool wordBreak(const string &s, unordered_set<string> &dict, bool *dp) {
        cout << s << ' ';
        int length = s.length();
        for (int i = 0; i < length; ++i) {
            if (dict.count(s.substr(0, i + 1)) && dp[i + 1]) {
                // cout << "true\n";
                return true;
            }
        }
        // cout << "false\n";
        return false;
    }
};

int main() {
    Solution so;
    string s = "catsandog";
    vector<string> dict({"cats", "dog", "sand", "and", "cat"});
    cout << so.wordBreak(s, dict) << endl;
    return 0;
}