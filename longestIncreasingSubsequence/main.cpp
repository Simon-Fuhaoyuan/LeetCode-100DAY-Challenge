#include <iostream>
#include <vector>
using namespace std;

// O(n^2)
class Solution1 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1)
            return size;
        int *dp = new int[size];
        dp[size - 1] = 1;
        int ans = 1;
        int tmp_max;
        for (int i = size - 2; i >= 0; --i) {
            tmp_max = 0;
            for (int j = i + 1; j < size; ++j) {
                if (dp[j] > tmp_max && nums[j] > nums[i])
                    tmp_max = dp[j];
            }
            dp[i] = ++tmp_max; // add this number to the subsequence
            if (tmp_max > ans)
                ans = tmp_max;
        }
        return ans;
    }
};

// O(nlogn)
// dp is not for storing the length, but the subsequence
// Each time we meet a number, check the dp, if this number is longer than
// the longest number in dp, add it directly to the tail of dp.
// Otherwise, check the dp and replace the minimum number which is bigger than this
// number to this number. This is because we always want the bigger number to be smaller,
// which is easier to add bigger number to the tail in the future.
// Note that at last, the numbers in dp may not be a valid subsequence, but it is in 
// increasing order, and its length is LIS.
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1)
            return size;
        int *dp = new int[size];
        int length = 0;
        int left, right, mid;
        for (int i = 0; i < size; ++i) {
            left = 0;
            right = length;
            if (right == 0 || dp[right - 1] < nums[i])
                dp[length++] = nums[i];
            else {
                while (left < right) {
                    mid = left + (right - left) / 2;
                    if (dp[mid] < nums[i])
                        left = mid + 1;
                    else
                        right = mid;
                }
                dp[left] = nums[i];
            }
        }
        return length;
    }
};

int main() {
    Solution2 s;
    vector<int> nums({10,9,2,5,3,7,101,18});
    cout << s.lengthOfLIS(nums) << endl;
    return 0;
}