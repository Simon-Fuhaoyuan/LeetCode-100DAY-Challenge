#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int size = nums.size();
        if (size < 2)
            return 0;
        unordered_map<int, int> hashMap;
        hashMap[0] = -1;
        int sum = 0, ans = 0;
        for (int i = 0; i < size; ++i) {
            sum += (nums[i] << 1) - 1;
            if (hashMap.count(sum))
                ans = max(ans, i - hashMap[sum]);
            else
                hashMap[sum] = i;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums({0,0,1,0,1,0,1,1,0,0,1,0,1,0,1,0,1,0,1,0});
    cout << s.findMaxLength(nums) << endl;
    return 0;
}