#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        vector<vector<int>> res;
        for (auto a : people) {
            res.insert(res.begin() + a[1], a);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> people({{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}});
    vector<vector<int>> ans = s.reconstructQueue(people);
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i][0] << ',' << ans[i][1] << ' ';
    cout << endl;
    return 0;
}