#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.length() == 0 || text2.length() == 0) return 0;

        int m = text1.length();
        int n = text2.length();
        int *dp = new int[(m + 1) * (n + 1)];

        for (int i = 0; i < m + 1; ++i)
            dp[i * (n + 1)] = 0;
        for (int i = 1; i < n + 1; ++i)
            dp[i] = 0;

        int common = 0;
        for (int i = 1; i < m + 1; ++i)
            for (int j = 1; j < n + 1; ++j) {
                if (text1[i - 1] == text2[j - 1])
                    common = 1;
                else
                    common = 0;
                dp[i * (n + 1) + j] = max(dp[(i - 1) * (n + 1) + j], dp[i * (n + 1) + j - 1], dp[(i - 1) * (n + 1) + j - 1] + common);
            }

        return dp[(m + 1) * (n + 1) - 1];
    }

private:
    int max(int x, int y, int z) {
        int tmp = x > y ? x : y;
        return tmp > z ? tmp : z;
    }
};

int main() {
    Solution s;
    string text1 = "abcbdab";
    string text2 = "bdcaba";

    cout << s.longestCommonSubsequence(text1, text2) << endl;
    return 0;
}