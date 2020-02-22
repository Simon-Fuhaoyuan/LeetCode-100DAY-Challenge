#include <iostream>
#include <vector>
using namespace std;

/**
 * HINT: The initial thought is DP, the value of each position is
 * the biggest product starting at that position.
 * However, this is not valid for arrays like [0, -2, -4], where
 * negative numbers' product is the biggest.
 * Thus, except for the initial DP, we should use another array
 * storing the possible smallest(most negative) product starting
 * at that position.
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return 0;
        vector<int> neg_nums(nums.begin(), nums.end());
        int max = nums[nums.size() - 1];

        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] > 0 && nums[i + 1] > 0)
                nums[i] *= nums[i + 1];
            else if (nums[i] < 0 && neg_nums[i + 1] < 0)
                nums[i] *= neg_nums[i + 1];
            if (neg_nums[i] > 0 && neg_nums[i + 1] < 0)
                neg_nums[i] *= neg_nums[i + 1];
            else if (neg_nums[i] < 0 && nums[i + 1] > 0)
                neg_nums[i] *= nums[i + 1];
            if (nums[i] > max)
                max = nums[i];
        }
        return max;
    }
};

int main() {
    Solution s;
    vector<int> nums({2, 4, -6, 8, -9, -10});
    cout << s.maxProduct(nums) << endl;
    return 0;
}