#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution1 {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            helper(s, i, i, ans);
            helper(s, i, i + 1, ans);
        }
        return ans;
    }
private:
    void helper(string& s, int i, int j, int& ans) {
        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            ans++;
            i--;
            j++;
        }
    }
};

// dp, dp[i][j] means if s[i:j+1] is a palindrome
class Solution {
public:
    int countSubstrings(string s) {
        int length = s.length();
        int ans = 0;
        vector<vector<bool>> dp(length, vector<bool>(length, false));
        for (int i = length - 1; i >= 0; --i) {
            for (int j = i; j < length; ++j) {
                if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])) {
                    ans++;
                    dp[i][j] = true;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    string str = "aaa";
    cout << s.countSubstrings(str) << endl;
    return 0;
}