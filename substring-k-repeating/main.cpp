#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) 
    {
        queue<string> que;
        map<char, int> table;
        map<char, int>::iterator it;
        string substr;
        int start, end;
        int ans = 0;

        que.push(s);
        while(!que.empty())
        {
            substr = que.front();
            que.pop();
            if (substr.length() <= ans) // this substring is toooo short
                continue;
            // create table
            for (int i = 0; i < substr.length(); ++i)
            {
                it = table.find(substr[i]);
                if (it != table.end())
                    it->second++;
                else
                    table.insert(make_pair(substr[i], 1));
            }
            // check substring
            start = end = 0;
            while(end < substr.length())
            {
                if (table[substr[end]] < k)
                {
                    if (end - start < ans)
                        start = ++end;
                    else
                    {
                        que.push(substr.substr(start, end - start));
                        start = ++end;
                    }
                }
                else
                    end++;
            }
            if (start == 0 && end > ans)
                ans = end;
            else // add the left substring
                que.push(substr.substr(start, end - start));
            // clear table and substr
            substr.clear();
            table.clear();
        }

        return ans;
    }
};

int main()
{
    Solution s;
    string str = "ababbc";

    cout << s.longestSubstring(str, 2) << endl;
    return 0;
}