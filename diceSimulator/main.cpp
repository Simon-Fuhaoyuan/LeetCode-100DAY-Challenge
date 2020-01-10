#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**HINT
 * Dynamic Programming
 */

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        int upperBound = 1e9 + 7;
        int ans = 0;
        int tmp;

        int *dp;
        dp = new int[(n + 1) * 6];
        for (int i = 0; i < 6; ++i) {
            dp[i] = 0;
            if (rollMax[i])
                dp[6 + i] = 1;
        }
        for (int i = 2; i <= n; ++i)
            for (int j = 0; j < 6; ++j) {
                dp[6 * i + j] = 0;
                tmp = 1;
                while (tmp <= rollMax[j] && tmp < i) {
                    for (int k = 0; k < 6; ++k)
                        if (k != j) {
                            dp[6 * i + j] += dp[6 * (i - tmp) + k];
                            dp[6 * i + j] %= upperBound;
                        }
                    tmp++;
                }
                if (tmp == i && tmp <= rollMax[j]) 
                    dp[6 * i + j] = (dp[6 * i + j] + 1) % upperBound;
            }
        for (int i = 0; i < 6; ++i) {
            ans += dp[n * 6 + i];
            ans %= upperBound;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(3);

    cout << s.dieSimulator(3, vec) << endl;
    return 0;
}