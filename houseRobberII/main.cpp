#include <iostream>
#include <vector>
using namespace std;

/**HINT
 * The difference from houseRobber is circle, so there's two senarioes.
 * 1. Use the first one, and the last one is banned, so it equals to nums[0] + rob(nums[2:-1])
 * 2. No using the first one, so it equals to rob([1:])
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return nums[0] > nums[1] ? nums[0] : nums[1];
        if (nums.size() == 3) return max(nums[0], nums[1], nums[2]);

        int ans1 = 0, ans2 = 0;
        vector<int> tmp(nums.begin() + 2, nums.end() - 1);
        ans1 = nums[0] + rob1(tmp);
        tmp.clear();
        tmp.assign(nums.begin() + 1, nums.end());
        ans2 = rob1(tmp);

        return ans1 > ans2 ? ans1 : ans2;
    }
private:
    // this function is the same to robI question
    int rob1(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return nums[0] > nums[1] ? nums[0] : nums[1];

        int size = nums.size();
        nums[size - 2] = nums[size - 2] > nums[size - 1] ? nums[size - 2] : nums[size - 1]; 
        for (int i = nums.size() - 3; i >= 0; --i) {
            nums[i] = nums[i] + nums[i + 2] > nums[i + 1] ? nums[i] + nums[i + 2] : nums[i + 1];
        }

        return nums[0];
    }

    int max(int x, int y, int z) {
        int tmp = x > y ? x : y;
        return tmp > z ? tmp : z;
    }
};

int main() {
    Solution s;
    vector<int> nums({1,2,3,1});

    cout << s.rob(nums) << endl;

    return 0;
}