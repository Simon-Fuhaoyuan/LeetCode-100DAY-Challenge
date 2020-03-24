#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        if (n == 0)
            return 0;
        
        vector<vector<bool>> counted(m, vector<bool>(n, false));
        int ans = 0;
        vector<int> servers;
        // check each row
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1)
                    servers.push_back(j);
            }
            if (servers.size() > 1) {
                ans += servers.size();
                for (int k = 0; k < servers.size(); ++k)
                    counted[i][servers[k]] = true;
            }
            servers.clear();
        }
        int total, not_counted;
        // check each colomn
        for (int j = 0; j < n; ++j) {
            total = not_counted = 0;
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] == 1) {
                    total++;
                    if (!counted[i][j])
                        not_counted++;
                }
            }
            if (total > 1)
                ans += not_counted;
        }
        return ans;
    }
};