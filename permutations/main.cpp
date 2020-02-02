#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        vector<int> tmp;
        return permute(nums, visited, tmp);
    }
private:
    vector<vector<int>> permute(vector<int>& nums, vector<bool> &visited, vector<int> tmp) {
        vector<vector<int>> ans;
        vector<vector<int>> part;
        if (tmp.size() == nums.size()) {
            ans.push_back(tmp);
            return ans;
        }
        tmp.push_back(0);
        for (int i = 0; i < nums.size(); ++i)
            if (!visited[i]) {
                tmp[tmp.size() - 1] = nums[i];
                visited[i] = true;
                part = permute(nums, visited, tmp);
                for (int j = 0; j < part.size(); ++j)
                    ans.push_back(part[j]);
                visited[i] = false;
            }
        
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums({1,2,3,4});
    vector<vector<int>> ans = s.permute(nums);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[0].size(); ++j)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
    return 0;
}