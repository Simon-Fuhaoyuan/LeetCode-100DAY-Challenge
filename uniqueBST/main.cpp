#include <iostream>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (n < 3)
            return n;
        int tmp;
        int *dp = new int[n + 1];
        dp[0] = 1; dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            tmp = 0;
            for (int j = 0; j < i; ++j)
                tmp += dp[j] * dp[i - j - 1];
            dp[i] = tmp;
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    cout << s.numTrees(3) << endl;
    return 0;
}