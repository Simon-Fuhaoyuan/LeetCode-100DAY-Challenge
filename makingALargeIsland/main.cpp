#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> group(m, vector<int>(n, 0));
        vector<int> groups;
        // find each connected area and record their area
        int tmp = 0, ans = 0;
        int groupId = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j] && grid[i][j]) {
                    tmp = 0;
                    dfs(grid, visited, tmp, i, j);
                    writeAns(grid, group, tmp, groupId, i, j);
                    if (tmp > ans)
                        ans = tmp;
                    groupId++;
                }
            }
        }
        // find each 0 point and calculate area after change
        // do not add repeated areas into one area
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!grid[i][j]) {
                    tmp = 1;
                    if (i > 0) {
                        tmp += grid[i - 1][j];
                        groups.push_back(group[i - 1][j]);
                    }
                    if (i < m - 1 && !repeat(groups, group[i + 1][j])) {
                        tmp += grid[i + 1][j];
                        groups.push_back(group[i + 1][j]);
                    }
                    if (j > 0 && !repeat(groups, group[i][j - 1])) {
                        tmp += grid[i][j - 1];
                        groups.push_back(group[i][j - 1]);
                    }
                    if (j < n - 1 && !repeat(groups, group[i][j + 1])) {
                        tmp += grid[i][j + 1];
                    }
                    if (tmp > ans)
                        ans = tmp;
                    groups.clear();
                }
            }
        }
        return ans;
    }
private:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int& area, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;
        if (visited[i][j] || !grid[i][j])
            return;
        area++;
        visited[i][j] = true;
        dfs(grid, visited, area, i - 1, j);
        dfs(grid, visited, area, i, j - 1);
        dfs(grid, visited, area, i + 1, j);
        dfs(grid, visited, area, i, j + 1);
    }
    void writeAns(vector<vector<int>>& grid, vector<vector<int>>& group, int ans, int groupId, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;
        if (grid[i][j] != 1)
            return;
        grid[i][j] = ans;
        group[i][j] = groupId;
        writeAns(grid, group, ans, groupId, i - 1, j);
        writeAns(grid, group, ans, groupId, i, j - 1);
        writeAns(grid, group, ans, groupId, i + 1, j);
        writeAns(grid, group, ans, groupId, i, j + 1);
    }
    bool repeat(vector<int>& groups, int groupId) {
        for (int i = 0; i < groups.size(); ++i)
            if (groups[i] == groupId)
                return true;
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid({{1,1},{0,1}});
    cout << s.largestIsland(grid) << endl;
    return 0;
}