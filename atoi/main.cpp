#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str)
    {
        int ans = 0;
        bool start_flag = false;
        bool negative_flag = false;
        for (int i = 0; i < str.length(); ++i)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                start_flag = true;
                if (ans > INT_MAX / 10)
                {
                    if (negative_flag) return INT_MIN;
                    else return INT_MAX;
                }
                ans *= 10;
                if (ans > INT_MAX - (str[i] - '0'))
                {
                    if (negative_flag) return INT_MIN;
                    else return INT_MAX;
                }
                ans += str[i] - '0';
            }
            else if (str[i] == ' ' && !start_flag)
                continue;
            else if (str[i] == '-' && !start_flag)
            {
                start_flag = true;
                negative_flag = true;
            }
            else if (str[i] == '+' && !start_flag)
                start_flag = true;
            else break;
        }
        if (negative_flag) ans *= -1;
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "    -42   ";
    int ans = sol.myAtoi(s);

    cout << ans << endl;

    return 0;
}
