#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, 0);
        int min_cnt, coin_idx;
        for (int i = 1; i <= amount; ++i) {
            min_cnt = -1;
            coin_idx = 0;
            while (coin_idx < coins.size()) {
                if (coins[coin_idx] > i)
                    break;
                if (dp[i - coins[coin_idx]] >= 0 && (min_cnt < 0 || 1 + dp[i - coins[coin_idx]] < min_cnt))
                    min_cnt = 1 + dp[i - coins[coin_idx]];
                coin_idx++;
            }
            dp[i] = min_cnt;
        }
        return dp[amount];
    }
};

int main() {
    Solution s;
    vector<int> coins({1,2,5});
    cout << s.coinChange(coins, 11) << endl;
    return 0;
}