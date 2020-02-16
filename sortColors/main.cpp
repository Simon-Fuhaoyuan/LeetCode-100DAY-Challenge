#include <iostream>
#include <vector>
using namespace std;

/**HINT
 * Use two pointers, start and end.
 * When face 0, put it to the front; when face 2, put it to the end.
 * Note that adjusting these two pointers is import.
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            if (nums[start] == 0) {
                nums.erase(nums.begin() + start);
                nums.insert(nums.begin(), 0);
                start++;
            }
            else if (nums[start] == 2) {
                nums.erase(nums.begin() + start);
                nums.push_back(2);
                end--;
            }
            else
                start++;
            if (start > end)
                break;
            if (nums[end] == 0) {
                nums.erase(nums.begin() + end);
                nums.insert(nums.begin(), 0);
                start++;
            }
            else if (nums[end] == 2) {
                nums.erase(nums.begin() + end);
                nums.push_back(2);
                end--;
            }
            else
                end--;
        }
    }
};

int main() {
    Solution s;
    vector<int> nums({2,0,2,1,1,0});
    s.sortColors(nums);
    for (int i = 0; i < nums.size(); ++i)
        cout << nums[i] << ' ';
    cout << endl;
    return 0;
}