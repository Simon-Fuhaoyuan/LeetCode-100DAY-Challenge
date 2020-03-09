#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int length = s.length();
        if (length == 0)
            return 0;
        int *dp = new int[length + 1];
        dp[length] = 1;
        dp[length - 1] = s[length - 1] == '0' ? 0 : 1;
        int cnt1, cnt2;
        for (int i = length - 2; i >= 0; --i) {
            cnt1 = s[i] == '0' ? 0 : dp[i + 1];
            cnt2 = (s[i] - '0') * 10 + s[i + 1] - '0';
            if (cnt2 > 9 && cnt2 <= 26)
                cnt2 = dp[i + 2];
            else
                cnt2 = 0;
            dp[i] = cnt1 + cnt2;
        }
        return dp[0];
    }
};

int main() {
    Solution s;
    string str = "226";
    cout << s.numDecodings(str) << endl;
    return 0;
}