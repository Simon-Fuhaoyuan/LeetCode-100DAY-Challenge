#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        if (size < 2)
            return 0;
        int start = 0, end = size - 1, mid;
        while (start <= end) {
            mid = (start + end) / 2;
            if (mid == 0) {
                if (nums[mid] > nums[mid + 1])
                    return 0;
                else {
                    start = mid + 1;
                    continue;
                }
            }
            else if (mid == size - 1) {
                if (nums[mid] > nums[mid - 1])
                    return mid;
                else {
                    end = mid - 1;
                    continue;
                }
            }
            else if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
                return mid;
            else if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1]) {
                start = mid + 1;
                continue;
            }
            else {
                end = mid - 1;
                continue;
            }
        }
        return (start + end) / 2;
    }
};

int main() {
    Solution s;
    vector<int> nums({1,2,4,7,5,8});
    cout << s.findPeakElement(nums) << endl;
    
    return 0;
}