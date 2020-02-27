#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();
        if (n == 0)
            return false;
        
        return helper(matrix, 0, 0, m, n, target);
    }
private:
    bool helper(vector<vector<int>>& matrix, int start_m, int start_n, int end_m, int end_n, int target) {
        if (start_m >= end_m || start_n >= end_n)
            return false;
        int tmp;
        // only one row
        if (end_m - start_m == 1) {
            tmp = start_n;
            while (tmp < end_n && matrix[start_m][tmp] <= target) {
                if (matrix[start_m][tmp] == target)
                    return true;
                tmp++;
            }
            return false;
        }
        // only one colomn
        else if (end_n - start_n == 1) {
            tmp = start_m;
            while (tmp < end_m && matrix[tmp][start_n] <= target) {
                if (matrix[tmp][start_n] == target)
                    return true;
                tmp++;
            }
            return false;
        }
        // partition into another square
        int diag_m = start_m, diag_n = start_n;
        while (diag_m < end_m && diag_n < end_n && matrix[diag_m][diag_n] <= target) {
            if (matrix[diag_m][diag_n] == target)
                return true;
            diag_m++;
            diag_n++;
        }
        return helper(matrix, start_m, diag_n, diag_m, end_n, target) ||
            helper(matrix, diag_m, start_n, end_m, diag_n, target);
    }
};

int main() {
    Solution s;
    vector<int> line1({1,   4,  7, 11, 15});
    vector<int> line2({2,   5,  8, 12, 19});
    vector<int> line3({3,   6,  9, 16, 22});
    vector<int> line4({10, 13, 14, 17, 24});
    vector<int> line5({18, 21, 23, 26, 30});
    vector<vector<int>> matrix({line1, line2, line3, line4, line5});
    cout << s.searchMatrix(matrix, 20) << endl;
    return 0;
}