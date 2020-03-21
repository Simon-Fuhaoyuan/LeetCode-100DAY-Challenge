#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size, 0);
        vector<int> buffer;
        buffer.push_back(nums[size - 1]);
        int start, end, mid;
        for (int i = size - 2; i >= 0; --i) {
            start = 0; end = buffer.size();
            while (start <= end) {
                mid = (start + end) / 2;
                if (mid < buffer.size() && buffer[mid] < nums[i]) {
                    start = mid + 1;
                    continue;
                }
                else if (mid - 1 >= 0 && buffer[mid - 1] >= nums[i]) {
                    end = mid - 1;
                    continue;
                }
                ans[i] = mid;
                buffer.insert(buffer.begin() + mid, nums[i]);
                break;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums({2,1,6,1});
    vector<int> ans = s.countSmaller(nums);
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}