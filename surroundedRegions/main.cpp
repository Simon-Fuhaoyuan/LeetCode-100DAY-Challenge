#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0)
            return;
        int n = board[0].size();
        if (n == 0)
            return;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            dfs(board, visited, i, 0);
            dfs(board, visited, i, n - 1);
        }
        for (int j = 1; j < n - 1; ++j) {
            dfs(board, visited, 0, j);
            dfs(board, visited, m - 1, j);
        }
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                if (!visited[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
private:
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int m, int n) {
        if (m < 0 || m >= board.size() || n < 0 || n >= board[0].size())
            return;
        if (visited[m][n] || board[m][n] == 'X')
            return;
        visited[m][n] = true;
        dfs(board, visited, m - 1, n);
        dfs(board, visited, m + 1, n);
        dfs(board, visited, m, n - 1);
        dfs(board, visited, m, n + 1);
    }
};

int main() {
    Solution s;
    vector<vector<char>> board({{'X','X','X','X'},
                                {'X','O','O','X'},
                                {'X','X','O','X'},
                                {'X','O','X','X'}});
    s.solve(board);
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j)
            cout << board[i][j] << ' ';
        cout << endl;
    }
    return 0;
}