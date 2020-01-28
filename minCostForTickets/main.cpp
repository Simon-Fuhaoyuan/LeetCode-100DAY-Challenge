#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int day_cnt = days.size();
        int *dp = new int[day_cnt + 1];
        dp[day_cnt] = 0;
        dp[day_cnt - 1] = min(costs[0], costs[1], costs[2]);
        int price_1, price_7, price_30;
        int index;
        for (int i = day_cnt - 2; i >= 0; i--) {
            price_1 = costs[0] + dp[i + 1];
            // find the first date that outside 7-day range
            index = i + 1;
            while (index < day_cnt && days[index] < days[i] + 7)
                index++;
            price_7 = costs[1] + dp[index];
            // find the first date that outside 30-day range
            index = i + 1;
            while (index < day_cnt && days[index] < days[i] + 30)
                index++;
            price_30 = costs[2] + dp[index];
            // find the minimum
            dp[i] = min(price_1, price_7, price_30);
        }

        return dp[0];
    }
private:
    int min(int x, int y, int z) {
        int tmp = x < y ? x : y;
        return tmp < z ? tmp : z;
    }
};

int main() {
    Solution s;
    vector<int> days({1,2,3,4,5,6,7,8,9,10,30,31});
    vector<int> costs({2,7,15});

    cout << s.mincostTickets(days, costs) << endl;
    return 0;
}