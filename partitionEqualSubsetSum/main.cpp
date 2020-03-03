#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int size = nums.size();
        for (int i = 0; i < size; ++i)
            sum += nums[i];
        if (sum % 2 == 1)
            return false;
        sum /= 2;
        sort(nums.begin(), nums.end());
        return helper(nums, size - 1, sum);
    }
private:
    bool helper(vector<int>& nums, int end, int target) {
        if (target == 0)
            return true;
        for (int i = end; i >= 0 && nums[i] <= target; --i) {
            if (helper(nums, i - 1, target - nums[i]))
                return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums({1,5,11,5});
    cout << s.canPartition(nums) << endl;
    return 0;
}