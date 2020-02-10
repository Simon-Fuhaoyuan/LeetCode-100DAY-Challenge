#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) { // use heap sort
        int size = nums.size();
        int hole, child, tmp;
        // construct the big heap
        for (int i = (size - 2) / 2; i >= 0; --i) {
            hole = i;
            tmp = nums[i];
            while (hole * 2 + 1 < size) {
                child = hole * 2 + 1;
                if (hole * 2 + 2 < size && nums[hole * 2 + 2] > nums[hole * 2 + 1])
                    child++;
                if (nums[child] > tmp) {
                    nums[hole] = nums[child];
                    hole = child;
                }
                else
                    break;
            }
            nums[hole] = tmp;
        }
        // for (int i = 0; i < size; ++i)
        //     cout << nums[i] << ' ';
        // cout << endl;
        // pop k times
        for (int i = 0; i < k - 1; ++i) {
            tmp = nums[--size];
            hole = 0;
            while (hole * 2 + 1 < size) {
                child = hole * 2 + 1;
                if (hole * 2 + 2 < size && nums[hole * 2 + 2] > nums[hole * 2 + 1])
                    child++;
                if (nums[child] > tmp) {
                    nums[hole] = nums[child];
                    hole = child;
                }
                else
                    break;
            }
            nums[hole] = tmp;
        }
        return nums[0];
    }
};

int main() {
    Solution s;
    vector<int> nums({3});
    cout << s.findKthLargest(nums, 1) << endl;
    return 0;
}