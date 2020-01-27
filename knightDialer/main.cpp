#include <iostream>
using namespace std;

class Solution {
private:
    const int MAX = 1e9 + 7;
public:
    int knightDialer(int N) {
        int **dp = new int*[N];
        for (int i = 0; i < N; ++i)
            dp[i] = new int[10];
        
        for (int i = 0; i < 10; ++i)
            dp[0][i] = 1;
        for (int i = 1; i < N; ++i) {
            dp[i][0] = (dp[i - 1][4] + dp[i - 1][6]) % MAX;
            dp[i][1] = (dp[i - 1][6] + dp[i - 1][8]) % MAX;
            dp[i][2] = (dp[i - 1][7] + dp[i - 1][9]) % MAX;
            dp[i][3] = (dp[i - 1][4] + dp[i - 1][8]) % MAX;
            dp[i][4] = ((dp[i - 1][3] + dp[i - 1][9]) % MAX + dp[i - 1][0]) % MAX;
            dp[i][5] = 0;
            dp[i][6] = ((dp[i - 1][1] + dp[i - 1][7]) % MAX + dp[i - 1][0]) % MAX;
            dp[i][7] = (dp[i - 1][2] + dp[i - 1][6]) % MAX;
            dp[i][8] = (dp[i - 1][1] + dp[i - 1][3]) % MAX;
            dp[i][9] = (dp[i - 1][2] + dp[i - 1][4]) % MAX;
        }

        int ans = 0;
        for (int i = 0; i < 10; ++i)
            ans = (ans + dp[N - 1][i]) % MAX;
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.knightDialer(3) << endl;

    return 0;
}