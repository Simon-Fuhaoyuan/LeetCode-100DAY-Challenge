#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans({-1, -1});
        int size = nums.size();
        if (size == 0)
            return ans;
        int start = 0, end = size - 1, pivot, mid;
        bool exist = false;
        // check if there exist target
        while (start <= end) {
            pivot = (start + end) / 2;
            if (nums[pivot] == target) {
                exist = true;
                break;
            }
            else if (nums[pivot] < target)
                start = pivot + 1;
            else
                end = pivot - 1;
        }
        if (!exist)
            return ans;
        // binary search for [start,pivot] and [pivot,end]
        int end_mid = pivot, start_mid = pivot;
        while (start <= end_mid) {
            mid = (start + end_mid) / 2;
            if (nums[mid] == target && (mid == 0 || nums[mid - 1] < target)) {
                ans[0] = mid;
                break;
            }
            else if (nums[mid] < target)
                start = mid + 1;
            else
                end_mid = mid - 1;
        }
        while (start_mid <= end) {
            mid = (start_mid + end) / 2;
            if (nums[mid] == target && (mid == size - 1 || nums[mid + 1] > target)) {
                ans[1] = mid;
                break;
            }
            else if (nums[mid] > target)
                end = mid - 1;
            else
                start_mid = mid + 1;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums({1,1,1});
    vector<int> ans = s.searchRange(nums, 1);
    cout << ans[0] << ' ' << ans[1] << endl;
    return 0;
}