#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (exist(board, visited, word, 1, i, j))
                        return true;
                    else
                        visited[i][j] = false;
                }
            }
        
        return false;
    }
private:
    bool exist(vector<vector<char>> &board, vector<vector<bool>> &visited, string word, int idx, int idx_row, int idx_col) {
        if (idx == word.length())
            return true;
        int rows = board.size();
        int cols = board[0].size();
        if (idx_row > 0 && !visited[idx_row - 1][idx_col] && board[idx_row - 1][idx_col] == word[idx]) {
            visited[idx_row - 1][idx_col] = true;
            if (exist(board, visited, word, idx + 1, idx_row - 1, idx_col))
                return true;
            else
                visited[idx_row - 1][idx_col] = false;
        }

        if (idx_row < rows - 1 && !visited[idx_row + 1][idx_col] && board[idx_row + 1][idx_col] == word[idx]) {
            visited[idx_row + 1][idx_col] = true;
            if (exist(board, visited, word, idx + 1, idx_row + 1, idx_col))
                return true;
            else
                visited[idx_row + 1][idx_col] = false;
        }
        
        if (idx_col > 0 && !visited[idx_row][idx_col - 1] && board[idx_row][idx_col - 1] == word[idx]) {
            visited[idx_row][idx_col - 1] = true;
            if (exist(board, visited, word, idx + 1, idx_row, idx_col - 1))
                return true;
            else
                visited[idx_row][idx_col - 1] = false;
        }
        
        if (idx_col < cols - 1 && !visited[idx_row][idx_col + 1] && board[idx_row][idx_col + 1] == word[idx]) {
            visited[idx_row][idx_col + 1] = true;
            if (exist(board, visited, word, idx + 1, idx_row, idx_col + 1))
                return true;
            else
                visited[idx_row][idx_col + 1] = false;
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<char> row1({'A','B','C','E'});
    vector<char> row2({'S','F','C','S'});
    vector<char> row3({'A','D','E','E'});
    vector<vector<char>> board({row1, row2, row3});

    cout << s.exist(board, "ABCCEE") << endl;
    return 0;
}