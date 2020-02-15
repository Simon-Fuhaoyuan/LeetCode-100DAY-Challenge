#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool oper(vector<int> &interval1, vector<int> &interval2) {
    return interval1[0] < interval2[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort by start time
        int size = intervals.size();
        sort(intervals.begin(), intervals.end(), oper);
        // check overlap
        vector<vector<int>> ans;
        int start, end;
        int idx = 0;
        while (idx < size) {
            start = intervals[idx][0];
            end = intervals[idx][1];
            idx++;
            while (idx < size && intervals[idx][0] <= end) {
                end = max(end, intervals[idx][1]);
                idx++;
            }
            ans.push_back(vector<int>({start, end}));
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> intervals({{1,3}, {2,2}, {15,15}, {8,15}});
    vector<vector<int>> ans = s.merge(intervals);
    for (int i = 0; i < ans.size(); ++i)
        cout << '(' << ans[i][0] << ',' << ans[i][1] << ") ";
    cout << endl;
    return 0;
}