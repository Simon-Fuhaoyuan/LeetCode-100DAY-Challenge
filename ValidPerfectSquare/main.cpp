#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 0;
        while (true)
        {
            if (i >= 46341) // sqrt(INT_MAX)
                return false;
            if (i * i == num)
                return true;
            if (i * i > num)
                return false;
            i++;
        }
    }
};

int main()
{
    Solution s;
    cout << s.isPerfectSquare(16) << endl;

    return 0;
}