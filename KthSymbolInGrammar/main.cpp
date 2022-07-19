#include <iostream>
#include <queue>
using namespace std;

// This question can be similar to the thoughts of binary tree.

class Solution {
public:
    int kthGrammar(int n, int k) {
        int idx = k - 1;
        queue<int> trajectory;
        int ans = 0;
        while (trajectory.size() < n - 1)
        {
            if (idx % 2 == 0) // Left child
                trajectory.push(0);
            else            // Right child
                trajectory.push(1);
            idx /= 2;
        }
        while (!trajectory.empty())
        {
            int traj = trajectory.front();
            trajectory.pop();
            ans = (ans + traj) % 2;
        }

        return ans;
    }
};

int main()
{
    Solution* s = new Solution();

    cout << s->kthGrammar(2, 2) << endl;
}
