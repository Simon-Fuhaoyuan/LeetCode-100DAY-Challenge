#include <iostream>
#include <vector>
using namespace std;

/**                                                         __
 * HINT: Split the rating value curve into parts like this /  \__
 * For each part, calculate minimal candies respectively.
 */

class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 0;
        int up, up_eq, down, down_eq;
        int index = 0;
        while (index < ratings.size()) {
            if (index == ratings.size() - 1) {
                ans += 1;
                break;
            }
            up = up_eq = down = down_eq = 0;
            while (index + 1 < ratings.size() && ratings[index] < ratings[index + 1]) {
                index++;
                up++;
            }
            while (index + 1 < ratings.size() && ratings[index] == ratings[index + 1]) {
                index++;
                up_eq++;
            }
            while (index + 1 < ratings.size() && ratings[index] > ratings[index + 1]) {
                index++;
                down++;
            }
            while (index + 1 < ratings.size() && ratings[index] == ratings[index + 1]) {
                index++;
                down_eq++;
            }
            int heap = max(up, down) + 1;
            if (up > 0) {
                ans += sum(1, up);
                if (up_eq == 0 && down == 0) { // finish
                    ans += up + 1;
                    break;
                }
            }
            if (up_eq == 0) {
                ans += heap + sum(2, down);
            }
            else {
                ans += up + 1;
                ans += sum(2, down + 1);
                ans += up_eq - 1;
            }
            if (down_eq > 0)
                ans += down_eq;
        }
        return ans;
    }
private:
    int sum(int start, int end) {
        int ans = 0;
        if (end < start)
            return ans;
        for (; start <= end; ++start)
            ans += start;
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> ratings({1,2,3,3,3,2,1});
    cout << s.candy(ratings) << endl;
    return 0;
}