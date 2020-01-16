#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // sort
        int tmp;
        bool flag = true;
        int size = nums.size();
        for (int i = 1; i < size && flag; ++i) {
            flag = false;
            for (int j = 0; j < size - i; ++j)
                if (nums[j] > nums[j + 1]) {
                    tmp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = tmp;
                    flag = true;
                }
        }
        // brute force
        int ans = 0;
        int sum;
        for (int i = 0; i < size; ++i)
            for (int j = i + 1; j < size; ++j) {
                sum = nums[i] + nums[j];
                for (int k = j + 1; k < size && nums[k] < sum; ++k)
                    ans++;
            }
        
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums({2,2,3,4});

    cout << s.triangleNumber(nums) << endl;
    return 0;
}