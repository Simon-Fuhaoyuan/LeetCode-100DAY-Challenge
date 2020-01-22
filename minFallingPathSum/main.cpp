#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    const int DEFAULT = 200;
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int size = A.size();
        if (size == 1) return A[0][0];
        // reconstruct matrix A using greedy algorithm
        int min_tmp;
        for (int i = 1; i < size; ++i)
            for (int j = 0; j < size; ++j) {
                if (j - 1 < 0)
                    min_tmp = min(DEFAULT, A[i - 1][j], A[i - 1][j + 1]);
                else if (j + 1 >= size)
                    min_tmp = min(A[i - 1][j - 1], A[i - 1][j], DEFAULT);
                else
                    min_tmp = min(A[i - 1][j - 1], A[i - 1][j], A[i - 1][j + 1]);
                A[i][j] += min_tmp;
            }
        // traverse A[size - 1] and find the smallest
        min_tmp = DEFAULT;
        for (int i = 0; i < size; ++i)
            if (min_tmp > A[size - 1][i])
                min_tmp = A[size - 1][i];

        return min_tmp;
    }
private:
    int min(int x, int y, int z) {
        int tmp = x < y ? x : y;
        return tmp < z ? tmp : z;
    }
};

int main() {
    Solution s;
    vector<int> a({1,2,3});
    vector<int> b({4,5,6});
    vector<int> c({7,8,9});
    vector<vector<int>> A;
    A.push_back(a);
    A.push_back(b);
    A.push_back(c);

    cout << s.minFallingPathSum(A) << endl;
    return 0;
}