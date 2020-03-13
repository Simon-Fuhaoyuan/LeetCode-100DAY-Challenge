#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int ele1, ele2=INT_MAX;
        int size = nums.size();
        if (size < 3)
            return false;
        ele1 = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= ele1)
                ele1 = nums[i];
            else if (nums[i] <= ele2)
                ele2 = nums[i];
            else
                return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums({5,4,3,2,1});
    cout << s.increasingTriplet(nums) << endl;
    return 0;
}