#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size <= 1)
            return 0;
        // dp[i] stores the max profit I can get if I buy on the ith day.
        int *dp = new int[size];
        dp[size - 1] = 0;
        int future_profit, max_profit, max_future_profit;
        max_future_profit = prices[size - 1];
        max_profit = 0;
        for (int i = size - 2; i >= 0; --i) {
            // if I buy today, the max profit I can get
            if (max_future_profit - prices[i] > max_profit) {
                max_profit = max_future_profit - prices[i];
            }
            dp[i] = max_profit;
            // if I sell today, the max profit I can get
            future_profit = (i + 2 < size) ? dp[i + 2] : 0; // cool down
            if (future_profit + prices[i] > max_future_profit)
                max_future_profit = future_profit + prices[i];
        }
        return max_profit;
    }
};

int main() {
    Solution s;
    vector<int> prices({1,2,3,0,2});
    cout << s.maxProfit(prices) << endl;
    return 0;
}