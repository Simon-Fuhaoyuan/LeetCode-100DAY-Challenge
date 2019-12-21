#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int UPPER_BOUND = 1E9 + 7;

class Solution {
public:
    int numWays(int steps, int arrLen)
    {
        int len = steps < arrLen ? steps : arrLen;
        vector<int> dp(len, 0);
        // initialize
        dp[0] = 1;
        dp[1] = 1;
        // iteration
        for (int i = 1; i < steps; ++i)
        {
            vector<int> tmp(len, 0);
            for (int j = 0; j < len; ++j)
            {
                // one more stay
                tmp[j] = dp[j];
                // one more right
                if (j >= 1) tmp[j] = (tmp[j] + dp[j - 1]) % UPPER_BOUND;
                // one more left
                if (j + 1 < len) tmp[j] = (tmp[j] + dp[j + 1]) % UPPER_BOUND;
                // break
                if (tmp[j] == 0) break;
            }
            dp = tmp; // save space
        }

        return dp[0];
    }
};

int main()
{
    Solution s;
    cout << s.numWays(2, 4) << endl;

    return 0;
}