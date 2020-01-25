#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans(T.size(), 0);
        stack<int> index;
        index.push(0);

        for (int i = 1; i < T.size(); ++i) {
            while(!index.empty() && T[i] > T[index.top()]) {
                ans[index.top()] = i - index.top();
                index.pop();
            }
            index.push(i);
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> T({73, 74, 75, 71, 69, 72, 76, 73});
    vector<int> ans = s.dailyTemperatures(T);

    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}