#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        // bfs
        vector<string> ans;
        queue<string> que_str;
        queue<int> que_int;
        string tmp_str;
        int tmp_int;
        que_str.push("(");
        que_int.push(1);
        while (!que_int.empty())
        {
            tmp_str = que_str.front();
            tmp_int = que_int.front();
            que_str.pop();
            que_int.pop();
            // satisfy the length requirements
            if (tmp_str.length() == 2 * n)
            {
                ans.push_back(tmp_str);
                continue;
            }
            // can only add '('
            if (tmp_int == 0)
            {
                tmp_str += '(';
                tmp_int++;
                que_str.push(tmp_str);
                que_int.push(tmp_int);
            }
            else
            {
                // both '(' and ')' can be added
                if ((tmp_str.length() + tmp_int) < 2 * n)
                {
                    que_str.push(tmp_str + '(');
                    que_int.push(tmp_int + 1);
                    que_str.push(tmp_str + ')');
                    que_int.push(tmp_int - 1);
                }
                // only ')' can be added
                else
                {
                    que_str.push(tmp_str + ')');
                    que_int.push(tmp_int - 1);
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> vec;
    vec = s.generateParenthesis(3);

    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i] << endl;
    return 0;
}