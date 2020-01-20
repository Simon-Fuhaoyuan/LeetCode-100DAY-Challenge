#include <iostream>
#include <string>
using namespace std;

/**HINT
 * This problem is the continuance of Probelm 'Longest Common Subsequence'.
 * We just need to find the length of longest common subsequence, let's say, L,
 * then, calculate (len(word1) - L + len(word2) - L)
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int LCS = longestCommonSubsequence(word1, word2);
        return word1.length() + word2.length() - 2 * LCS;
    }
private:
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
    int max(int x, int y, int z) {
        int tmp = x > y ? x : y;
        return tmp > z ? tmp : z;
    }
};

int main() {
    Solution s;
    string word1 = "eat";
    string word2 = "sea";

    cout << s.minDistance(word1, word2) << endl;
    return 0;
}