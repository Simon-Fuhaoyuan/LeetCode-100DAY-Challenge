#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        unordered_map<int, int> times;
        int size = nums.size();
        int target = size / 2;
        for (int i = 0; i < size; ++i) {
            if (times.count(nums[i])) {
                if (++times[nums[i]] > target)
                    return nums[i];
            }
            else {
                times.insert(make_pair(nums[i], 1));
            }
        }
        return 0;
    }
};