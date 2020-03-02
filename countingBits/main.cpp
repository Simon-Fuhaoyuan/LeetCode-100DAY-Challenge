#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans({0});
        int idx = 1;
        int size = 0;
        while (idx <= num) {
            size = ans.size();
            for (int i = 0; i < size && idx <= num; ++i && ++idx)
                ans.push_back(ans[i] + 1);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> ans = s.countBits(5);
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
    cout << endl;
}