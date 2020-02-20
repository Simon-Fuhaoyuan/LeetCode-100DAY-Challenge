#include <iostream>
#include <vector>
using namespace std;

/**
 * HINT: Xor is amazing!!!!!!!!
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i)
            ans ^= nums[i];
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums({1,2,3,3,1});
    cout << s.singleNumber(nums) << endl;
    return 0;
}