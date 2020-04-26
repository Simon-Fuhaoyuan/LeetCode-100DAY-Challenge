#include <iostream>
#include <vector>
using namespace std;
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 */
class BinaryMatrix {
    public:
        int get(int row, int col);
        vector<int> dimensions();
};


class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> size = binaryMatrix.dimensions();
        int start = 0, end = size[1] - 1, mid;
        int ans = -1, last_one = -1;
        while (start <= end) {
            mid = (start + end) / 2;
            if (last_one != -1 && binaryMatrix.get(last_one, mid) == 1) {
                ans = mid;
                end = mid - 1;
                continue;
            }
            last_one = -1;
            for (int i = 0; i < size[0]; ++i) {
                if (binaryMatrix.get(i, mid) == 1) {
                    ans = mid;
                    end = mid - 1;
                    last_one = i;
                    break;
                }
            }
            if (last_one == -1) {
                start = mid + 1;
            }
        }
        return ans;
    }
};