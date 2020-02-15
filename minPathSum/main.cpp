#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m < 1)
            return 0;
        int n = grid[0].size();
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i != m - 1 && j != n - 1)
                    grid[i][j] += min(grid[i + 1][j], grid[i][j + 1]);
                else if (i != m - 1)
                    grid[i][j] += grid[i + 1][j];
                else if (j != n - 1)
                    grid[i][j] += grid[i][j + 1];
            }
        }

        return grid[0][0];
    }
};

int main() {
    Solution s;
    vector<int> num1({1,3,1});
    vector<int> num2({1,5,1});
    vector<int> num3({4,2,1});
    vector<vector<int>> grid({num1, num2, num3});
    cout << s.minPathSum(grid) << endl;
    return 0;
}