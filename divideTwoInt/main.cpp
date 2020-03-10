#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) // overflow
            return INT_MAX;
        
        unsigned int ans = 0;
        unsigned int mask = 0x80000000;
        unsigned int abs_dividend = dividend;
        if (dividend < 0) {
            abs_dividend -= 1;
            abs_dividend = ~abs_dividend;
        }
        unsigned int abs_divisor = divisor;
        if (divisor < 0) {
            abs_divisor -= 1;
            abs_divisor = ~abs_divisor;
        }
        cout << abs_divisor << endl;
        unsigned int div = 0;
        for (int i = 0; i < 32; ++i) {
            ans = ans << 1;
            div = div << 1;
            if ((mask & abs_dividend) != 0) {
                div++;
            }
            if (div >= abs_divisor) {
                div -= abs_divisor;
                ans++;
            }
            mask = mask >> 1;
        }
        if (dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0) {
            ans = ~ans;
            ans++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.divide(-100, -3) << endl;
    
    return 0;
}