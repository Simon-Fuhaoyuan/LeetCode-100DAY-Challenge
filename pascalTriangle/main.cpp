#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> tmp;
        if (numRows == 0)
            return ans;
        ans.push_back(vector<int>({1}));
        for (int i = 1; i < numRows; ++i) {
            tmp.clear();
            tmp.push_back(1);
            for (int j = 1; j < i; ++j)
                tmp.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
            tmp.push_back(1);
            ans.push_back(tmp);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> ans = s.generate(5);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
    return 0;
}