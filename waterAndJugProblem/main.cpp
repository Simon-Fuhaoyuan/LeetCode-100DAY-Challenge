#include <iostream>
using namespace std;

/**
 * hint: if we can get the water, it means m*x + n*y = z
 */

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return z == 0 || (x + y >= z && z % gcd(x, y) == 0);
    }
    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }
};

int main() {
    Solution s;
    int x = 5;
    int y = 3;
    int z = 4;
    cout << s.canMeasureWater(x, y, z) << endl;
    return 0;
}