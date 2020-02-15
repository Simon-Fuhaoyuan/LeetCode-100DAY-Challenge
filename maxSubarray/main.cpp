#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int *dp = new int[size];
        dp[size - 1] = nums[size - 1];
        int max = nums[size - 1];
        for (int i = size - 2; i >= 0; --i) {
            dp[i] = nums[i];
            if (dp[i + 1] > 0)
                dp[i] += dp[i + 1];
            if (dp[i] > max)
                max = dp[i];
        }
        return max;
    }
};

int main() {
    Solution s;
    vector<int> nums({-2,1,-3,4,-1,2,1,-5,4});
    cout << s.maxSubArray(nums) << endl;
    return 0;
}