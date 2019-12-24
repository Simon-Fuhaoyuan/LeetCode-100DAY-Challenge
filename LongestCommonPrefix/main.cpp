#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string ans = "";
        int size = strs.size();
        if (size == 0) return ans;
        int smallest_length = strs[0].size();
        char tmp;

        for (int i = 1; i < size; ++i)
            if (strs[i].size() < smallest_length)
                smallest_length = strs[i].size();

        for (int i = 0; i < smallest_length; ++i)
        {
            tmp = strs[0][i];
            for (int j = 1; j < size; ++j)
                if (strs[j][i] != tmp)
                    return ans;
            ans += tmp;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> strs;
    strs.push_back("flower");
    strs.push_back("flow");
    strs.push_back("fluat");
    string ans = s.longestCommonPrefix(strs);
    cout << ans << endl;
    return 0;
}
