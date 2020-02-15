#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        // more conditions
        int *dp = new int[n];
        dp[n - 1] = 1;
        dp[n - 2] = 2;
        for (int i = n - 3; i >= 0; --i)
            dp[i] = dp[i + 1] + dp[i + 2];
        return dp[0];
    }
};

int main() {
    Solution s;
    cout << s.climbStairs(10) << endl;
}