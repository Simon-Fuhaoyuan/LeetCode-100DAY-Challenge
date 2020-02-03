#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);

        return permuteUnique(nums, visited, vector<int>());
    }
private:
    vector<vector<int>> permuteUnique(const vector<int> &nums, vector<bool> &visited, vector<int> tmp) {
        vector<vector<int>> ans;
        vector<vector<int>> part;
        if (tmp.size() == nums.size()) {
            ans.push_back(tmp);
            return ans;
        }
        int i = 0;
        int last = nums[i];
        // find the first number which is not visited
        for (; i < nums.size() && visited[i]; ++i)
            continue;
        tmp.push_back(last);
        while (i < nums.size()) {
            last = nums[i];
            tmp[tmp.size() - 1] = last;
            visited[i] = true;
            part = permuteUnique(nums, visited, tmp);
            for (int j = 0; j < part.size(); ++j)
                ans.push_back(part[j]);
            part.clear();
            visited[i] = false;
            while (i < nums.size() && (visited[i] || nums[i] == last))
                i++;
        }

        return ans;
    }
};

int main() {
    vector<int> nums({1,2,1,3,3});
    Solution s;
    vector<vector<int>> ans = s.permuteUnique(nums);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[0].size(); ++j)
            cout << ans[i][j] << ' ';
        cout << endl;
    }

    return 0;
}