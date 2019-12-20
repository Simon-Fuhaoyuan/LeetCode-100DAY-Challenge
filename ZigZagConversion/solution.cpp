#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) 
    {
        if (numRows == 1)
            return s;
        string ans;
        int interval = 2 * (numRows - 1);
        int sub_interval;
        int index;
        for (int i = 0; i < numRows; ++i)
        {
            sub_interval = interval - 2 * i;
            index = i;
            while (index < s.length())
            {
                ans += s[index];
                index += sub_interval == 0 ? interval : sub_interval;
                sub_interval = interval - sub_interval;
            }
        }
        return ans;
    }
};