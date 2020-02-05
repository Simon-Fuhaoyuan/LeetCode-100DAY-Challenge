#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump_dp(vector<int>& nums) { // time exceed limit
        const int max = INT_MAX;
        int size = nums.size();
        int tmp;
        int *dp = new int[size];
        dp[size - 1] = 0;
        for (int i = size - 2; i >= 0; --i) {
            dp[i] = -1; // -1 means this step cannot goto final
            tmp = max;
            for (int j = 1; j <= nums[i] && i + j < size; ++j) {
                if (dp[i + j] != -1 && dp[i + j] + 1 < tmp)
                    tmp = dp[i + j] + 1;
            }
            if (tmp < max)
                dp[i] = tmp;
        }

        return dp[0];
    }
    int jump(vector<int> &nums) { // greedy, each time, find the index that can reach the farthest place
        if (nums.size() == 1)
            return 0;
        int ans = 0;
        int index = 0;
        int tmp, max, max_index;
        while (index + nums[index] < nums.size() - 1) {
            max = 0;
            for (int i = 1; i <= nums[index]; ++i) {
                tmp = index + i + nums[index + i];
                if (tmp > max) {
                    max = tmp;
                    max_index = index + i;
                }
            }
            index = max_index;
            ans++;
        }
        ans++;

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums({2,3,1,1,4});
    cout << s.jump(nums) << endl;
    return 0;
}