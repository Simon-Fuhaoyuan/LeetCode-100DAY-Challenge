#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if (nums.empty())
            return ans;
        int max_idx = findMax(nums, 0, k);
        ans.push_back(nums[max_idx]);
        int end_idx = k, start_idx = 1;
        while (end_idx < nums.size()) {
            if (max_idx < start_idx)
                max_idx = findMax(nums, start_idx, k);
            else if (nums[end_idx] >= nums[max_idx])
                max_idx = end_idx;
            ans.push_back(nums[max_idx]);
            end_idx++;
            start_idx++;
        }
        return ans;
    }
private:
    int findMax(vector<int> &nums, int start, int k) {
        int max_idx = start;
        for (int i = start + 1; i < start + k; ++i) {
            if (nums[i] >= nums[max_idx])
                max_idx = i;
        }
        return max_idx;
    }
};

int main() {
    Solution s;
    vector<int> nums({1,3,-1,-3,5,3,6,7});
    vector<int> ans = s.maxSlidingWindow(nums, 3);
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}