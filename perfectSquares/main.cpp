#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int *dp = new int[n + 1];
        dp[0] = 0;
        int j, tmp, min;
        for (int i = 1; i <= n; ++i) {
            min = i;
            for (j = 1; j * j <= i; ++j) {
                tmp = i - j * j;
                if (dp[tmp] + 1 < min)
                    min = dp[tmp] + 1;
            }
            dp[i] = min;
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    cout << s.numSquares(12) << endl;
    return 0;
}