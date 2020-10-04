#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        for (int i = 0; i < intervals.size(); ++i) {
            for (int j = 0; j < intervals.size(); ++j) {
                if (i == j)
                    continue;
                if (intervals[i][0] >= intervals[j][0] && intervals[i][1] <= intervals[j][1]) {
                    intervals.erase(intervals.begin() + i);
                    i--;
                    break;
                }
            }
        }
        return intervals.size();
    }
};