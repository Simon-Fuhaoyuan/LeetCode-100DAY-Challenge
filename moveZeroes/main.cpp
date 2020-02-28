#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (!nums[i]) {
                nums.erase(nums.begin() + i);
                zero_cnt++;
                i--;
            }
        }
        for (int i = 0; i < zero_cnt; ++i)
            nums.push_back(0);
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0, ptr = 0;
        int size = nums.size();
        while (ptr < size) {
            while (ptr < size && nums[ptr] == 0)
                ptr++;
            if (ptr >= size)
                break;
            nums[idx] = nums[ptr];
            idx++;
            ptr++;
        }
        while (idx < size) {
            nums[idx] = 0;
            idx++;
        }
    }
};

int main() {
    Solution s;
    vector<int> nums({0,1,0,3,5});
    s.moveZeroes(nums);
    for (int i = 0; i < nums.size(); ++i)
        cout << nums[i] << ' ';
    cout << endl;
    return 0;
}