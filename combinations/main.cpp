#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        queue<vector<int>> buffer;
        vector<int> tmp;
        int size = 0;
        for (int i = 1; i <= n - k + 1; ++i)
            buffer.push(vector<int>(1, i));
        if (k == 1) {
            while (!buffer.empty()) {
                ans.push_back(buffer.front());
                buffer.pop();
            }
            return ans;
        }
        while (buffer.front().size() != k - 1) {
            tmp = buffer.front();
            buffer.pop();
            size = tmp.size();
            tmp.push_back(tmp[size - 1]);
            for (int i = tmp[size - 1] + 1; i <= n - k + size + 1; ++i) {
                tmp[size]++;
                buffer.push(tmp);
            }
        }
        while (!buffer.empty()) {
            tmp = buffer.front();
            buffer.pop();
            tmp.push_back(tmp[k - 2]);
            for (int i = tmp[k - 2] + 1; i <= n; ++i) {
                tmp[k - 1]++;
                ans.push_back(tmp);
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> ans = s.combine(5, 3);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j)
            cout << ans[i][j] << ' ';
        cout << endl;
    }

    return 0;
}