#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashMap(nums.begin(), nums.end());
        int start, end;
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            start = end = 0;
            if (hashMap.count(nums[i]) == 0)
                continue;
            while (hashMap.count(nums[i] - start - 1)) {
                start++;
                hashMap.erase(nums[i] - start);
            }
            while (hashMap.count(nums[i] + end + 1)) {
                end++;
                hashMap.erase(nums[i] + end);
            }
            ans = max(ans, start + end + 1);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums({100, 4, 200, 1, 3, 2});
    cout << s.longestConsecutive(nums) << endl;
    return 0;
}