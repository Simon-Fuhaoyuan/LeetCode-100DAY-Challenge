#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int tmp;
        // judge 1 to nums[0], 2 to nums[1], so and so force.
        for (int i = 0; i < n; ++i) {
            while (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                tmp = nums[i];
                nums[i] = nums[tmp - 1];
                nums[tmp - 1] = tmp;
            }
        }
        // check from the first
        for (int i = 0; i < n; ++i)
            if (nums[i] != i + 1)
                return i + 1;
        return n + 1;
    }
};

int main() {
    Solution s;
    vector<int> nums({3,4,-1,1});
    cout << s.firstMissingPositive(nums) << endl;
    for (int i = 0; i < nums.size(); ++i)
        cout << nums[i] << ' ';
    cout << endl;
    return 0;
}