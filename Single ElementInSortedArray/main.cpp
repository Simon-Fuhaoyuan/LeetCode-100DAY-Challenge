#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int size = nums.size();
        int start = 0;
        int end = size - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            bool even = (mid % 2 == 0);
            if (mid > 0 && nums[mid - 1] == nums[mid]) {
                if (even)
                    end = mid - 2;
                else
                    start = mid + 1;
            }
            else if (mid < size - 1 && nums[mid + 1] == nums[mid]) {
                if (even)
                    start = mid + 2;
                else
                    end = mid - 1;
            }
            else if (mid > 0 && mid < size - 1)
                return nums[mid];
        }
        return nums[start];
    }
};


int main()
{
    Solution s;
    int test[10] = {1,1,3,3,4,4,5,8,8};
    vector<int> nums;
    nums.assign(test, test + 9);
    cout << s.singleNonDuplicate(nums) << endl;
    return 0;
}
