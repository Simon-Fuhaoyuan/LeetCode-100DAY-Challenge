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
        
    }
};

int main() {
    Solution s;
    string str = "aaa";
    cout << s.countSubstrings(str) << endl;
    return 0;
}