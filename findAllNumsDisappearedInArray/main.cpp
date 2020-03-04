#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            while (nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1)
                ans.push_back(i + 1);
        }
        return ans;
    }
private:
    void swap(int& x, int& y) {
        int tmp = x;
        x = y;
        y = tmp;
    }
};

int main() {
    Solution s;
    vector<int> nums({4,3,2,7,8,2,3,1});
    vector<int> ans = s.findDisappearedNumbers(nums);
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}