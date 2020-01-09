#include <vector>
#include <iostream>
using namespace std;

/**HINT
 * From start, find the index of first different element.
 * From end, find the index of first different element.
 * Use these two indeces to get the size of subarray.
 */

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        int tmp;
        // get the start index
        while(start != end) {
            if (nums[start] > nums[start + 1])
                break;
            start++;
        }
        if (start == end) return 0;
        // tmp = nums[start + 1];
        // while (start != 0) {
        //     if (nums[start - 1] > tmp)
        //         start--;
        //     else
        //         break;
        // }
        // get the end index
        while(end != start) {
            if (nums[end] < nums[end - 1])
                break;
            end--;
        }
        // tmp = nums[end - 1];
        // while(end != nums.size() - 1) {
        //     if (nums[end + 1] < tmp)
        //         end++;
        //     else
        //         break;
        // }

        // check valid
        int minVal = nums[start], maxVal = nums[start];
        for (int i = start + 1; i <= end; ++i) {
            if (nums[i] < minVal) minVal = nums[i];
            else if (nums[i] > maxVal) maxVal = nums[i];
        }

        while (start >= 1 && nums[start - 1] > minVal)
            start--;
        while (end < nums.size() - 1 && nums[end + 1] < maxVal)
            end++;
        return end - start + 1;
    }
};

int main() {
    Solution s;
    int arr[7] = {2, 3, 3, 2, 4, 9, 15};
    vector<int> vec(arr, arr + 5);
    cout << s.findUnsortedSubarray(vec) << endl;

    return 0;

}