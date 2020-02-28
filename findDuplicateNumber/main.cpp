#include <vector>
#include <iostream>
using namespace std;

// nums have duplicate numbers, so there will be cycle
// but this solution is difficult to think up.
class Solution1 {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0, t = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }
        while (true) {
            slow = nums[slow];
            t = nums[t];
            if (slow == t) break;
        }
        return slow;
    }
};

// bit manipulation
// check 32 bits iterately, if the duplicate number have 1 on some bit
// then the number of 1s on this bit of the nums must be bigger than 
// that on [1, n].
class Solution2 {
public:
    int findDuplicate(vector<int> &nums) {
        int ans = 0;
        int cnt1, cnt2, bit;
        int n = nums.size();
        for (int i = 0; i < 32; ++i) {
            bit = 1 << i;
            cnt1 = cnt2 = 0;
            for (int j = 0; j < n; ++j) {
                if ((j & bit) > 0)
                    cnt1++;
                if ((nums[j] & bit) > 0)
                    cnt2++;
            }
            if (cnt2 > cnt1)
                ans += bit;
        }
        return ans;
    }
};

int main() {
    Solution2 s;
    vector<int> nums({1,3,4,2,2});
    cout << s.findDuplicate(nums) << endl;
    return 0;
}