#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        int ans = 0, sum = 0;
        unordered_map<int, int> hashMap;
        hashMap[0] = 1;
        for (int i = 0; i < size; ++i) {
            sum += nums[i];
            ans += hashMap[sum - k];
            hashMap[sum]++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums({1,1,1});
    cout << s.subarraySum(nums, 2) << endl;
    return 0;
}