#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C - A) * (D - B);
        int area2 = (G - E) * (H - F);
        bool overlap = true;
        // vertical direction
        if (A >= G || E >= C)
            overlap = false;
        // horizontal direction
        if (overlap && (B >= H || F >= D))
            overlap = false;
        // no overlap
        if (!overlap)
            return area1 + area2;
        // have overlap
        vector<int> x({A, C, E, G});
        vector<int> y({B, D, F, H});
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        int overlap_area = (x[2] - x[1]) * (y[2] - y[1]);
        return area1 - overlap_area + area2;
    }
};

int main() {
    Solution s;
    cout << s.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;

    return 0;
}