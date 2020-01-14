#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        vector<unordered_map<int, bool> > dp(stones.size() - 1, unordered_map<int, bool>());
        if (stones[0] != 0 || stones[1] != 1)
            return false;
        
        return canCross(stones, dp, 0, 1);
    }
private:
    bool canCross(vector<int> &stones, vector<unordered_map<int, bool> > &dp, int currentIdx, int step) {
        int pos = stones[currentIdx] + step;
        for (; currentIdx < stones.size() && pos > stones[currentIdx]; ++currentIdx)
            continue;
        if (currentIdx == stones.size()) return false;
        if (stones[currentIdx] != pos) return false;
        if (currentIdx == stones.size() - 1) return true;

        bool flag1, flag2, flag3;
        if (step - 1 > 0 && dp[currentIdx].find(step - 1) == dp[currentIdx].end()) {
            flag1 = canCross(stones, dp, currentIdx, step - 1);
            dp[currentIdx].insert(make_pair(step - 1, flag1));
        }
        else if (step - 1 > 0)
            flag1 = dp[currentIdx][step - 1];
        else
            flag1 = false;
        
        if (flag1) return true;

        if (dp[currentIdx].find(step) == dp[currentIdx].end()) {
            flag2 = canCross(stones, dp, currentIdx, step);
            dp[currentIdx].insert(make_pair(step, flag2));
        }
        else
            flag2 = dp[currentIdx][step];
        
        if (flag2) return true;

        if (dp[currentIdx].find(step + 1) == dp[currentIdx].end()) {
            flag3 = canCross(stones, dp, currentIdx, step + 1);
            dp[currentIdx].insert(make_pair(step + 1, flag3));
        }
        else
            flag3 = dp[currentIdx][step + 1];
        
        if (flag3) return true;
        
        return false;
    }
};

int main() {
    Solution s;
    vector<int> stones({0,1,2,3,4,8,9,11});

    cout << s.canCross(stones) << endl;
    return 0;
}