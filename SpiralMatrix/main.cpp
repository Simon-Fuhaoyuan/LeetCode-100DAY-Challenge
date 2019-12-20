#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> ans;
        int row = matrix.size();
        if (row == 0) return ans;
        int column = matrix[0].size();
        int current_circle = 0;
        while(current_circle <= row / 2)
        {
            if (column - current_circle *2 == 0)
                break;
            if (row - 2 * current_circle == 0)
                break;
            for (int i = current_circle; i < column - current_circle; ++i)
                ans.push_back(matrix[current_circle][i]);
            if (row - 2 * current_circle == 1)
                break;
            for (int i = current_circle + 1; i < row - current_circle; ++i)
                ans.push_back(matrix[i][column - current_circle - 1]);
            if (column - current_circle *2 == 0)
                break;
            for (int i = column - current_circle - 2; i >= current_circle; --i)
                ans.push_back(matrix[row - current_circle - 1][i]);
            if (column - current_circle *2 == 1)
                break;
            for (int i = row - current_circle - 2; i > current_circle; --i)
                ans.push_back(matrix[i][current_circle]);
            current_circle++;
        }
        return ans;
    }
};

int main()
{
    Solution s;

    return 0;
}