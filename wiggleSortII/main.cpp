#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        int size = nums.size();
        int small = (size - 1) / 2;
        int big = size - 1;
        for (int i = 0; i < size; ++i) {
            nums[i] = (i % 2) == 0 ? tmp[small--] : tmp[big--];
        }
    }
};