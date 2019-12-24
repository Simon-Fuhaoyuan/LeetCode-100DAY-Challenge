#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x)
    {
        bool negative_flag = false;
        if (x < 0)
        {
            if (x == INT_MIN) return 0;
            x *= -1;
            negative_flag = true;
        }
        int ans = 0;
        while(x != 0)
        {
            if (ans > INT_MAX / 10) return 0;
            ans *= 10;
            ans += (x % 10);
            x /= 10;
        }
        if (negative_flag) ans *= -1;
        return ans;
    }
};

int main()
{
    Solution s;
    int x = -123467;
    cout << s.reverse(x) << endl;
    return 0;
}
