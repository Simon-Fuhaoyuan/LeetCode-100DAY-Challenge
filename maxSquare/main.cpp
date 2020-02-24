#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0)
            return 0;
        int n = matrix[0].size();
        if (n == 0)
            return 0;
        // dp
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (matrix[0][i] == '1') {
                ans = 1;
                dp[0][i] = 1;
            }
        for (int i = 1; i < m; ++i)
            if (matrix[i][0] == '1') {
                ans = 1;
                dp[i][0] = 1;
            }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]) + 1;
                    if (dp[i][j] > ans)
                        ans = dp[i][j];
                }
            }
        }
        return ans * ans;
    }
private:
    int min(int x, int y, int z) {
        int tmp = x < y ? x : y;
        return tmp < z ? tmp : z;
    }
};

int main() {

}