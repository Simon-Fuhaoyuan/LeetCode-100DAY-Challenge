#include <vector>
#include <iostream>
using namespace std;

/**
 * HINT: dp[i][j] stores the max score to burst balloons in [i,j]
 * dp[i][j] = max(i<=k<=j)(dp[i][j], dp[i][k-1] + dp[k+1][j] + nums[i-1]*nums[k]*nums[j+1])
 */

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int size = nums.size();
        // add 1 at head and tail
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        // create dp
        vector<vector<int>> dp(size + 2, vector<int>(size + 2, 0));
        for (int len = 1; len <= size; ++len) {
            for (int i = 1; i <= size - len + 1; ++i) {
                int j = i + len - 1;
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + nums[i - 1] * nums[k] * nums[j + 1]);
                }
            }
        }
        return dp[1][size];
    }
};

int main() {
    Solution s;
    vector<int> nums({3,1,5,8});
    cout << s.maxCoins(nums) << endl;
    return 0;
}