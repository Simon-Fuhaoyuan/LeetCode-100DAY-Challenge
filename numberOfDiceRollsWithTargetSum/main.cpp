#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>> dp(d + 1, vector<int>(target + 1, 0));
        const int MOD = 1e9 + 7;
        for (int i = 1; i <= min(f, target); ++i) {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= d; ++i) {
            int maximum = f * i > target - (d - i) ? target - (d - i) : f * i;
            for (int j = i; j <= maximum; ++j) {
                for (int k = 1; k <= min(j, f); ++k) {
                    dp[i][j] += dp[i - 1][j - k];
                    dp[i][j] %= MOD;
                }
            }
        }

        return dp[d][target];
    }
};

int main() {
    Solution s;
    int d = 30;
    int f = 30;
    int target = 500;
    cout << s.numRollsToTarget(d, f, target) << endl;

    return 0;
}