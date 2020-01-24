#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int origin_r = nums.size();
        int origin_c = nums[0].size();
        if (origin_r * origin_c != r * c)
            return nums;
        
        int counter_c = 0; // count the origin c
        int counter_r = 0; // count the origin r
        vector<vector<int>> ans(r, vector<int>(c, 0));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j) {
                ans[i][j] = nums[counter_r][counter_c];
                counter_c++;
                if (counter_c == origin_c) {
                    counter_c = 0;
                    counter_r++;
                }
            }
        
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> nums;
    vector<int> a({1,2});
    vector<int> b({3,4});
    nums.push_back(a);
    nums.push_back(b);

    vector<vector<int>> ans = s.matrixReshape(nums, 4, 1);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[0].size(); ++j)
            cout << ans[i][j] << ' ';
        cout << endl;
    }

    return 0;
}