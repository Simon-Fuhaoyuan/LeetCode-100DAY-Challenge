#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        int dp[m+1][n+1];
        dp[0][0] = 0;
        
        for (int i=0; i<=m; i++) {
            for (int j=0; j<=n; j++) {
                if (i == 0 && j == 0) continue;
                
                if (i == 0) {
                    dp[i][j] = dp[i][j-1] + 1;
                }
                else if (j == 0) {
                    dp[i][j] = dp[i-1][j] + 1;
                }
                else {
                    if (word1[i-1] != word2[j-1])
                        dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
                    else
                        dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    Solution s;
    string word1 = "pneumonoultramicroscopicsilicovolcanoconiosis";
    string word2 = "ultramicroscopically";
    cout << s.minDistance(word1, word2) << endl;

    return 0;
}