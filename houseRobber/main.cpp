#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
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
};

int main() {
    Solution s;
    vector<int> nums({2,7,9,3,1});

    cout << s.rob(nums) << endl;
    return 0;
}