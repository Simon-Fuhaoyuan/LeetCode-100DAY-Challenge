#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int mask1 = (m & n);
        int mask2 = (m ^ n);
        vector<int> bits(32, 1);
        for (int i = 0; i < 32; ++i) {
            if ((mask2 & 1) > 0)
                bits[i] = 0;
            mask2 = mask2 >> 1;
        }
        mask2 = 0;
        bool flag = true;
        for (int i = 0; i < 32; ++i) {
            mask2 = mask2 << 1;
            if (!bits[31 - i])
                flag = false;
            if (flag) {
                mask2 += 1;
            }
        }
        return (mask1 & mask2);
    }
};

int main() {
    Solution s;
    cout << s.rangeBitwiseAnd(1,1) << endl;
    return 0;
}