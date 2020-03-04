#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int size = nums.size();
        vector<unordered_map<int, int>> dp(size + 1, unordered_map<int,int>());
        dp[0][0] = 1;
        for (int i = 0; i < size; ++i) {
            for (auto it = dp[i].begin(); it != dp[i].end(); ++it) {
                dp[i + 1][it->first + nums[i]] += it->second;
                dp[i + 1][it->first - nums[i]] += it->second;
            }
        }
        return dp[size][S];
    }
};

int main() {
    Solution s;
    vector<int> nums({9,7,0,3,9,8,6,5,7,6});
    cout << s.findTargetSumWays(nums, 2) << endl;
    return 0;
}