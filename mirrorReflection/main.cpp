#include <iostream>
using namespace std;

/**HINT
 * Repeat the p*p square some times at X direction and Y direction.
 * Until the light from (0,0) to (p,q) can reach the northeast corner.
 * Then parse the repeat times for X direction and Y direction, get the answer
 */

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int LCM = p; // least common multiple
        while (LCM % q != 0) {
            LCM += p;
        }
        int times_y = LCM / p;
        int times_x = LCM / q;
        times_x = times_x % 2;
        times_y = times_y % 2;
        if (times_x == 0 && times_y == 1)
            return 2;
        else if (times_x == 1 && times_y == 0)
            return 0;
        else
            return 1;
    }
};

int main() {
    Solution s;

    cout << s.mirrorReflection(4, 4) << endl;
    return 0;
}