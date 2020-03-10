#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;
        if (n == 1)
            return x;
        bool negative = n < 0;
        bool int_min = n == INT_MIN;
        if (int_min)
            n ++;
        if (negative)
            n *= -1;
        bool odd = n % 2 == 1;
        double ans = myPow(x, n / 2);
        ans *= ans;
        if (odd)
            ans *= x;
        if (int_min)
            ans *= x;
        if (negative)
            ans = 1 / ans;
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.myPow(4.0, -2) << endl;
    return 0;
}