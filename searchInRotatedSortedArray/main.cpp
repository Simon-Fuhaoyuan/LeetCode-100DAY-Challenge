#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot = 0;
        int size = nums.size();
        if (size == 0)
            return -1;
        int start = 0, end = size - 1, mid;
        // binary search for pivot
        while (end - start > 1 && nums[end] < nums[start]) {
            mid = (start + end) / 2;
            if (nums[mid] < nums[end])
                end = mid;
            else
                start = mid;
        }
        pivot = nums[start] < nums[end] ? start : end;
        // binary search for target
        start = pivot;
        end = pivot + size - 1;
        while (end >= start) {
            mid = (start + end) / 2;
            if (nums[mid % size] == target)
                return mid % size;
            else if (nums[mid % size] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums({0});
    cout << s.search(nums, 0) << endl;
    return 0;
}