#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board)
    {
        bool *valid;
        valid = new bool[9];
        for (int i = 0; i < 9; ++i)
            valid[i] = true;

        // valid rows
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                    continue;
                else
                {
                    if (!valid[board[i][j] - '1'])
                        return false;
                    valid[board[i][j] - '1'] = false;
                }
            }
            recover(valid);
        }
        // valid columns
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[j][i] == '.')
                    continue;
                else
                {
                    if (!valid[board[j][i] - '1'])
                        return false;
                    valid[board[j][i] - '1'] = false;
                }
            }
            recover(valid);
        }
        // valid each 3x3 square
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
            {
                for (int m = 0; m < 3; ++m)
                    for (int n = 0; n < 3; ++n)
                    {
                        if (board[3 * i + m][3 * j + n] == '.')
                            continue;
                        else
                        {
                            if (!valid[board[3 * i + m][3 * j + n] - '1'])
                                return false;
                            valid[board[3 * i + m][3 * j + n] - '1'] = false;
                        }
                    }
                recover(valid);
            }
        delete[]valid;
        return true;
    }
    void recover(bool *valid)
    {
        for (int i = 0; i < 9; ++i)
            valid[i] = true;
    }
};

int main()
{
    return 0;
}