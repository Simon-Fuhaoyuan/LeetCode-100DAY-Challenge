#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        if (n == 0)
            return 0;
        // record visit info
        queue<vector<int>> bfs;
        int ans = 0;
        // traverse the grid
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    // bfs
                    grid[i][j] = '0';
                    bfs.push(vector<int>({i, j}));
                    while (!bfs.empty()) {
                        int x = bfs.front()[0];
                        int y = bfs.front()[1];
                        bfs.pop();
                        helper(x - 1, y, grid, bfs);
                        helper(x, y - 1, grid, bfs);
                        helper(x + 1, y, grid, bfs);
                        helper(x, y + 1, grid, bfs);
                    }
                    ans++;
                }
            }
        }
        return ans;
    }
private:
    void helper(int i, int j, vector<vector<char>> &grid, queue<vector<int>> &bfs) {
        if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size()) {
            if (grid[i][j] == '1') {
                grid[i][j] = '0';
                bfs.push(vector<int>({i, j}));
            }
        }
    }
};

int main() {
    Solution s;
    vector<char> l1({'1', '1', '0', '0', '0'});
    vector<char> l2({'1', '1', '0', '0', '0'});
    vector<char> l3({'0', '0', '1', '0', '0'});
    vector<char> l4({'0', '0', '0', '1', '1'});
    // vector<char> l5({'1', '1', '1', '1', '0'});
    vector<vector<char>> grid({l1, l2, l3, l4});
    cout << s.numIslands(grid) << endl;
    return 0;
}