#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s)
    {
        int ans = 0;
        char curr;
        string::iterator it = s.begin();
        while(it != s.end())
        {
            curr = *it;
            it++;
            switch(curr)
            {
            case 'M':
                ans += 1000;
                break;
            case 'D':
                ans += 500;
                break;
            case 'C':
                if (it != s.end() && (*it == 'M' || *it == 'D'))
                    ans -= 100;
                else
                    ans += 100;
                break;
            case 'L':
                ans += 50;
                break;
            case 'X':
                if (it != s.end() && (*it == 'C' || *it == 'L'))
                    ans -= 10;
                else
                    ans += 10;
                break;
            case 'V':
                ans += 5;
                break;
            case 'I':
                if (it != s.end() && (*it == 'V' || *it == 'X'))
                    ans -= 1;
                else
                    ans += 1;
                break;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.romanToInt("MCMXCIV") << endl;

    return 0;
}