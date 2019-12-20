#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) 
    {
        if (n == 1) return 1;
        int ans = 0;
        stack<int> stk;
        vector<int> chessboard;
        for (int i = 0; i < n * n; ++i)
            chessboard.push_back(0);
        int level = 0;
        int target = 0;

        for (int i = 0; i < n; ++i)
        {
            stk.push(i);
            setFlag(chessboard, 0, i, n, false);
            level = 1;
            target = 0;
            while(!stk.empty())
            {
                while(target < n && chessboard[n * level + target] != 0)
                    target++;
                if (target == n) // no position for queen
                {
                    level--;
                    target = stk.top();
                    stk.pop();
                    setFlag(chessboard, level, target, n, true);
                    target++;
                    continue;
                }
                setFlag(chessboard, level, target, n, false);
                stk.push(target);
                level++;
                target = 0;

                if (level == n)
                {
                    ans++;
                    level--;
                    target = stk.top();
                    stk.pop();
                    setFlag(chessboard, level, target, n, true);
                    target++;
                    continue;
                }
            }
        }

        return ans;
    }
    void setFlag(vector<int> &chessboard, int level, int target, int n, bool flag)
    {
        int signal = flag ? -1 : 1;
        // horizontal
        for (int i = 0; i < n; ++i)
            chessboard[level * n + i] += signal;
        // vertical
        for (int i = 0; i < n; ++i)
            chessboard[target + i * n] += signal;
        // diagonal
        int l = level - 1;
        int t = target - 1;
        while(l >= 0 && t >= 0)
        {
            chessboard[l * n + t] += signal;
            l--;
            t--;
        }
        l = level - 1;
        t = target + 1;
        while(l >= 0 && t < n)
        {
            chessboard[l * n + t] += signal;
            l--;
            t++;
        }
        l = level + 1;
        t = target - 1;
        while(l < n && t >= 0)
        {
            chessboard[l * n + t] += signal;
            l++;
            t--;
        }
        l = level + 1;
        t = target + 1;
        while(l < n && t < n)
        {
            chessboard[l * n + t] += signal;
            l++;
            t++;
        }
    }
};

int main()
{
    Solution s;
    cout << s.totalNQueens(2) << endl;

    return 0;
}