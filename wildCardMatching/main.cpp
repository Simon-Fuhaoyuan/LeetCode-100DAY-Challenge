#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p) 
    {
        string::iterator last_s = s.begin();
        string::iterator last_p = p.begin();
        string::iterator it_s = s.begin();
        string::iterator it_p = p.begin();

        while(it_s != s.end() && it_p != p.end())
        {
            // equal or p is '?'
            if (*it_s == *it_p || *it_p == '?')
            {
                it_s++;
                it_p++;
                continue;
            }
            // p is '*'
            if (*it_p == '*')
            {
                it_p++;
                if (it_p == p.end()) return true;
                last_p = it_p;
                last_s = it_s + 1;
                continue;
            }
            // not equal, no *
            if (last_p == p.begin()) return false;
            // not equal, but with *
            it_p = last_p;
            it_s = last_s;
            while (it_s != s.end() && *it_s != *it_p && *it_p != '?')
                it_s++;
            last_s = it_s + 1;
        }

        if (it_p == p.end() && it_s == s.end())
            return true;

        
        if (it_p == p.end() && last_p != p.begin() && it_s != s.end())
            while(it_s != s.end())
            {
                it_p = last_p;
                it_s = last_s;
                while(it_s != s.end() && *it_s != *it_p && *it_p != '?')
                    it_s++;
                last_s = it_s + 1;
                while(it_s != s.end() && it_p != p.end())
                {
                    if (*it_s == *it_p || *it_p == '?')
                    {
                        it_s++;
                        it_p++;
                        continue;
                    }
                    else break;
                }
            }

        if (it_p == p.end() && it_s == s.end())
            return true;

        while (it_s == s.end() && it_p != p.end())
        {
            if (*it_p != '*') return false;
            it_p++;
        }

        if (it_p == p.end() && it_s == s.end())
            return true;

        return false;
    }
};

int main()
{
    Solution s;
    string s1 = "abb";
    string s2 = "**??";

    cout << s.isMatch(s1, s2) << endl;

    return 0;
}