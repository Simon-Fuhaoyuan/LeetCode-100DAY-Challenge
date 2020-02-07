#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> ans;
        vector<int> tmp;
        ans.push_back(tmp);
        if (size == 0)
            return ans;

        int pointer = 0;
        vector<bool> mask(size + 1, false);
        mask[0] = true;
        while (!mask[size]) {
            tmp.clear();
            for (int i = 0; i < size; ++i)
                if (mask[i])
                    tmp.push_back(nums[i]);
            ans.push_back(tmp);
            pointer = 0;
            while (mask[pointer]) {
                mask[pointer] = false;
                pointer++;
            }
            mask[pointer] = true;
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums({1,2,3});
    vector<vector<int>> ans = s.subsets(nums);

    for (int i = 0; i < ans.size(); ++i) {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); ++j)
            cout << ans[i][j] << ' ';
        cout << "]\n";
    }
    return 0;
}