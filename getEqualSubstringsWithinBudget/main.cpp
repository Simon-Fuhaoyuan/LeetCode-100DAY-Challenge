#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int length = s.length();
        int *costs = new int[length];
        for (int i = 0; i < length; ++i)
            costs[i] = abs(s[i] - t[i]);
        int start = 0, end = 0;
        int totalCost = 0, ans = 0, tmp = 0;
        while (end < length) {
            while (end < length && totalCost + costs[end] <= maxCost) {
                totalCost += costs[end++];
            }
            if (end - start > ans)
                ans = end - start;
            if (start == end) {
                start++;
                end++;
            }
            else {
                totalCost -= costs[start];
                start++;
            }
        }
        return ans;
    }
};

int main() {
    Solution so;
    string s = "abcd";
    string t = "acde";
    cout << so.equalSubstring(s, t, 0) << endl;
    return 0;
}