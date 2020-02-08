#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        // merge even and odd scenario
        int target1 = (size + 1) / 2;
        int target2 = (size + 2) / 2;
        // starting pos of nums1 and nums2
        int start1 = 0, start2 = 0;
        // target is a loop variable
        int target = target1;
        int var1, var2;
        // indicator, indicating which array is target from.
        int target_arr = -1;
        while (target != 1) {
            // an array may reach its end
            if (start1 >= nums1.size()) {
                target_arr = 2;
                start2 = start2 + target - 1;
                break;
            }
            else if (start2 >= nums2.size()) {
                target_arr = 1;
                start1 = start1 + target - 1;
                break;
            }
            // like binary search, if a half array's maximum is smaller than the other one
            // then, this half array cannot have target, so we can delete this half array
            // thus, we can shorten the search range by half
            var1 = (start1 + target / 2 - 1 < nums1.size()) ? nums1[start1 + target / 2 - 1] : INT_MAX;
            var2 = (start2 + target / 2 - 1 < nums2.size()) ? nums2[start2 + target / 2 - 1] : INT_MAX;
            if (var1 < var2)
                start1 += target / 2;
            else
                start2 += target / 2;
            target -= target / 2;
        }
        if (target_arr == -1) {
            if (start1 >= nums1.size())
                target_arr = 2;
            else if (start2 >= nums2.size())
                target_arr = 1;
            else
                target_arr = nums1[start1] < nums2[start2] ? 1 : 2;
        }
        int median1 = target_arr == 1 ? nums1[start1] : nums2[start2];
        // odd
        if (target1 == target2)
            return median1 / 1.0;
        // even
        else {
            if (target_arr == 1)
                start1++;
            else
                start2++;
            int median2 = (start1 < nums1.size() ? nums1[start1] : INT_MAX) < 
                (start2 < nums2.size() ? nums2[start2] : INT_MAX) ?
                nums1[start1] : nums2[start2];
            return (median1 + median2) / 2.0;
        }
    }
};

int main() {
    Solution s;
    vector<int> nums1({1});
    vector<int> nums2({});
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}