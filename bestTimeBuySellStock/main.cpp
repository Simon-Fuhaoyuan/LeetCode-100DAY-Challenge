#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int idx = 0;
        int min_idx = 0, max_idx = 0;
        int size = prices.size();
        while (idx < size) {
            // find a bottom
            while (idx + 1 < size && prices[idx] >= prices[idx + 1])
                idx++;
            if (idx >= size)
                break;
            else if (prices[idx] < prices[min_idx])
                min_idx = idx;
            idx++;
            // find a heap
            while (idx + 1 < size && prices[idx] <= prices[idx + 1])
                idx++;
            if (idx >= size)
                break;
            else if (prices[idx] - prices[min_idx] > ans)
                ans = prices[idx] - prices[min_idx];
            idx++;
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