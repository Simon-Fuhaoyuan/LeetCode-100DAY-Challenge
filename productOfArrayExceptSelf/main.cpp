#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.begin(), nums.end());
        // nums[i] records nums[0] * nums[1] * ... * nums[i - 1]
        int tmp = nums[0], last;
        nums[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            last = tmp;
            tmp = nums[i];
            nums[i] = nums[i - 1] * last;
        }
        // ans[i] records ans[i + 1] * ans[i + 2] * ... * ans[size - 1]
        tmp = ans[ans.size() - 1];
        ans[ans.size() - 1] = 1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            last = tmp;
            tmp = ans[i];
            ans[i] = ans[i + 1] * last;
        }
        // ans[i] *= nums[i]
        for (int i = 0; i < nums.size(); ++i) {
            ans[i] *= nums[i];
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums({1,2});
    vector<int> ans = s.productExceptSelf(nums);
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}