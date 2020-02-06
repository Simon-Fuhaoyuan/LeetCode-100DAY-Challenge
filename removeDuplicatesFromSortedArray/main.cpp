#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        int unique = 0;
        int tmp = 0;
        while (index < nums.size()) {
            tmp = nums[index++];
            nums[unique++] = tmp;
            while (nums[index] == tmp)
                index++;
        }

        return unique;
    }
};

int main() {
    Solution s;
    vector<int> nums({0,0,1,1,1,2,2,3,3,4});
    int num = s.removeDuplicates(nums);
    for (int i = 0; i < num; ++i)
        cout << nums[i] << ' ';
    cout << endl;

    return 0;
}