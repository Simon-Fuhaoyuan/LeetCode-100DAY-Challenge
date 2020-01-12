#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) return false;
        int total = 0;
        int size = nums.size();
        for (int i = 0; i < size; ++i)
            total += nums[i];
        if (total % 4 != 0) return false;

        total /= 4;
        // sort
        int tmp = 0;
        int pos = 0;
        for (int i = 0; i < size - 1; ++i)
        {
            tmp = nums[i];
            pos = i;
            for (int j = i + 1; j < size; ++j)
                if (nums[j] < tmp)
                {
                    tmp = nums[j];
                    pos = j;
                }
            nums[pos] = nums[i];
            nums[i] = tmp;
        }

        return makesquare(nums, total, 0);
    }
private:
    bool makesquare(vector<int> &nums, const int target, const int current) {
        int i = nums.size() - 1; // i is the index of elements
        int tmp;

        // find the first value that is equal to or smaller than (target - current)
        while (i >= 0 && nums[i] > target - current)  
            i--;
        // try these values one by one, check if their sum can be target
        for (; i >= 0; --i) {
            tmp = nums[i];
            nums.erase(nums.begin() + i);
            if (nums.empty())
                return true;
            if (tmp == target - current && makesquare(nums, target, 0))
                return true;
            else if (tmp != target - current && makesquare(nums, target, current + tmp))
                return true;
            // one spectial scenario: the value is the first element and no other values fit, we cannot get a valid answer
            else if (current == 0) { 
                nums.insert(nums.begin() + i, tmp);
                return false;
            }
            nums.insert(nums.begin() + i, tmp);
        }
        return false;
    }
};

void makeVector(vector<int> &vec, int *arr, int size)
{
    for (int i = 0; i < size; i++)
        vec.push_back(arr[i]);
}

int main()
{
    Solution s;
    //int arr[12] = {10,6,5,5,5,3,3,3,2,2,2,2};
    int arr[15] = {3,3,3,3,4,4,4,4,4,4,5,5,5,5,16};
    //int arr[5] = {3,3,3,3,4};
    vector<int> v;
    makeVector(v, arr, 15);
    bool flag = s.makesquare(v);
    cout << flag << endl;
    return 0;
}
