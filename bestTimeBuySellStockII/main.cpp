#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int ans = 0;
        int index = 0, bottom;
        while (index < prices.size() - 1 && prices[index] >= prices[index + 1])
            index++;
        while (index < prices.size()) {
            bottom = index;
            while (index + 1 < prices.size() && prices[index] <= prices[index + 1])
                index++;
            ans += prices[index] - prices[bottom];
            index++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> prices({7,1,5,3,6,4});
    cout << s.maxProfit(prices) << endl;
    return 0;
}