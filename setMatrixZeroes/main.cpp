#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_set<int> row, col;
        // traverse the matrix to record zeroes
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    if (row.count(i) == 0)
                        row.insert(i);
                    if (col.count(j) == 0)
                        col.insert(j);
                }
            }
        // modify the matrix
        // rows
        for (auto it = row.begin(); it != row.end(); ++it) 
            for (int j = 0; j < n; ++j)
                matrix[*it][j] = 0;
        
        // colomns
        for (auto it = col.begin(); it != col.end(); ++it) 
            for (int i = 0; i < m; ++i)
                matrix[i][*it] = 0;
    }
};

int main() {
    Solution s;
    vector<int> x({1,2,3});
    vector<int> y({4,0,6});
    vector<int> z({7,8,0});
    vector<vector<int>> matrix({x, y, z});

    s.setZeroes(matrix);
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j)
            cout << matrix[i][j] << ' ';
        cout << endl;
    }

    return 0;
}