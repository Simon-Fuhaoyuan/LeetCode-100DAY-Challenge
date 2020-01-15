#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        // sort the candidates
        bool flag = true;
        int tmp;
        for (int i = 1; flag && i < candidates.size(); ++i) {
            flag = false;
            for (int j = 0; j < candidates.size() - i; ++j) {
                if (candidates[j] > candidates[j + 1]) {
                    tmp = candidates[j];
                    candidates[j] = candidates[j + 1];
                    candidates[j + 1] = tmp;
                    flag = true;
                }
            }
        }
        // for (int i = 0; i < candidates.size(); ++i)
        //     cout << candidates[i] << ' ';
        // cout << endl;
        // find answers
        vector<vector<int> > ans;
        queue<vector<int> > que;
        vector<int> temp;
        int tmp_sum = 0;
        for (int i = candidates.size() - 1; i >= 0; --i) {
            temp.clear();
            temp.push_back(candidates[i]);
            que.push(temp);
            while (!que.empty()) {
                temp = que.front();
                que.pop();
                tmp_sum = 0;
                for (int j = 0; j < temp.size(); ++j)
                    tmp_sum += temp[j];
                
                if (tmp_sum == target) {
                    ans.push_back(temp);
                    continue;
                }
                
                for (int j = 0; j < candidates.size() && candidates[j] <= temp[temp.size() - 1] 
                        && candidates[j] + tmp_sum <= target; ++j) {
                    if (candidates[j] + tmp_sum < target) {
                        temp.push_back(candidates[j]);
                        que.push(temp);
                        temp.erase(temp.begin() + temp.size() - 1);
                    }
                    else if (candidates[j] + tmp_sum == target) {
                        temp.push_back(candidates[j]);
                        ans.push_back(temp);
                        break;
                    }
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> candidates({7,3});
    vector<vector<int> > ans = s.combinationSum(candidates, 17);

    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
    return 0;
}