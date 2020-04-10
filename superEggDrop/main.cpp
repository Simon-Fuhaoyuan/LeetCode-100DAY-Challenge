#include <iostream>
#include <vector>
using namespace std;

// dp[k - 1][n] means the minimum number of moves with k eggs and n floors.
// However, this method only works when K and N is rather small
class Solution1 {
public:
    int superEggDrop(int K, int N) {
        if (K == 1)
            return N;
        if (N <= 1)
            return N;
        int min_step;
        vector<vector<int>> dp(K, vector<int>(N + 1, 0));
        for (int i = 0; i < N; ++i)
            dp[0][i + 1] = i + 1;
        for (int k = 1; k < K; ++k) {
            dp[k][1] = 1;
            for (int n = 2; n <= N; ++n) {
                min_step = N;
                for (int i = 1; i <= n; ++i)
                    min_step = min(min_step, 1 + max(dp[k - 1][i - 1], dp[k][n - i]));
                dp[k][n] = min_step;
            }
        }
        return dp[K - 1][N];
    }
};

// dp[k - 1][m] means the maximum floors we can know with certainty with k eggs and m moves.
// Convert our thoughts, traverse m from 1 to N, and check whether the maximum floors is greater than N.
// dp[k][m] = dp[k - 1][m - 1] + dp[k - 1][m] + 1
class Solution {
public:
    int superEggDrop(int K, int N) {
        if (K == 1)
            return N;
        if (N <= 1)
            return N;
        int min_step;
        vector<vector<int>> dp(K, vector<int>());
        for (int k = 0; k < K; ++k)
            dp[k].push_back(0);
        for (int m = 1; m <= N; ++m) {
            dp[0].push_back(m);
            for (int k = 1; k < K; ++k) {
                dp[k].push_back(dp[k - 1][m - 1] + dp[k][m - 1] + 1);
            }
            if (dp[K - 1][m] >= N)
                return m;
        }
        return N;
    }
};

int main() {
    Solution s;
    cout << s.superEggDrop(4, 10000) << endl;
    return 0;
}