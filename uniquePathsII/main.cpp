#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0)
            return 0;
        int n = obstacleGrid[0].size();
        if (n == 0)
            return 0;
        long **dp = new long*[m + 1]; // long type here is to prevent overflow
        for (int i = 0; i <= m; ++i)
            dp[i] = new long[n + 1];
        
        for (int i = 0; i < m + 1; ++i)
            dp[i][n] = 0;
        for (int i = 0; i < n + 1; ++i)
            dp[m][i] = 0;
        dp[m][n - 1] = 1; // a virtual point, used for normalizing the following codes
        for (int i = m - 1; i >= 0; --i)
            for (int j = n - 1; j >= 0; --j) {
                if (!obstacleGrid[i][j])
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
                else
                    dp[i][j] = 0;
            }
        return dp[0][0];
    }
};

int main() {
    Solution s;
    vector<int> line1({0,0,0});
    vector<int> line2({0,1,0});
    vector<vector<int>> grid({line1, line2, line1});
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            cout << grid[i][j] << ' ';
        cout << endl;
    }
    cout << s.uniquePathsWithObstacles(grid) << endl;
    return 0;
}