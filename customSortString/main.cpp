#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string customSortString(string S, string T)
    {
        string ans;
        string::iterator it = T.begin();
        vector<int> dict(26, 0);
        // make the dict of T
        while(it != T.end())
        {
            dict[*it - 'a']++;
            it++;
        }
        // traverse string S and print characters both in S and T
        it = S.begin();
        while(it != S.end())
        {
            for (int i = 0; i < dict[*it - 'a']; ++i)
                ans += *it;
            dict[*it - 'a'] = 0;
            it++;
        }
        // add the characters that didn't exist in S
        for (int i = 0; i < 26; ++i)
            if (dict[i])
                for (int j = 0; j < dict[i]; ++j)
                    ans += ('a' + i);

        return ans;
    }
};

int main()
{
    Solution s;
    string S = "cba";
    string T = "abcd";
    cout << s.customSortString(S, T) << endl;

    return 0;
}