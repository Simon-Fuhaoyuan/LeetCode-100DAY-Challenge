#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> relation(N, vector<int>());
        for (int i = 0; i < dislikes.size(); ++i) {
            relation[dislikes[i][0] - 1].push_back(dislikes[i][1] - 1);
            relation[dislikes[i][1] - 1].push_back(dislikes[i][0] - 1);
        }
        vector<int> groups(N, 0);
        for (int i = 0; i < N; ++i) {
            if (groups[i] != 0)
                continue;
            groups[i] = 1;
            queue<int> bfs;
            bfs.push(i);
            while (!bfs.empty()) {
                int person1 = bfs.front();
                bfs.pop();
                for (int j = 0; j < relation[person1].size(); ++j) {
                    int person2 = relation[person1][j];
                    if (groups[person1] == groups[person2])
                        return false;
                    if (groups[person2] == 0) {
                        groups[person2] = -1 * groups[person1];
                        bfs.push(person2);
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    return 0;
}
