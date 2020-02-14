#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n < 2)
            return;
        int tmp;
        for (int i = 0; i < n / 2; ++i) {
            for (int j = i; j < n - i - 1; ++j) {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = tmp;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> l1({5, 1, 9, 11});
    vector<int> l2({2, 4, 8, 10});
    vector<int> l3({13, 3, 6, 7});
    vector<int> l4({15,14,12,16});
    vector<vector<int>> matrix({l1, l2, l3, l4});
    s.rotate(matrix);
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j)
            cout << matrix[i][j] << ' ';
        cout << endl;
    }
    return 0;
}