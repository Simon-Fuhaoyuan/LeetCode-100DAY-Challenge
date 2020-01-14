#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int target = nums.size() - 1;
        if (target == 0) return true;
        vector<bool> dp(target, false);
        bool flag = false;
        for (int i = target - 1; i >= 0; --i) {
            if (nums[i] >= target - i) {
                dp[i] = true;
                flag = true;
                continue;
            }
            if (flag)
                while (nums[i] > 0) {
                    if (dp[i + nums[i]]) {
                        dp[i] = true;
                        break;
                    }
                    nums[i]--;
                }
        }

        return dp[0];
    }
};

int main() {
    Solution s;
    vector<int> nums({3,2,1,0,4});

    cout << s.canJump(nums) << endl;
    return 0;
}