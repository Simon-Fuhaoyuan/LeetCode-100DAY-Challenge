#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> items;
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (items.count(nums[i]))
                items[nums[i]]++;
            else
                items[nums[i]] = 1;
        }

        // cout << items[0] << endl << endl;

        auto it = items.begin();
        if (k == 0) {
            while (it != items.end()) {
                if (it->second > 1)
                    ans++;
                it++;
            }
        }
        else {
            while (it != items.end()) {
                if (items.count(it->first + k))
                    ans++;
                if (items.count(it->first - k))
                    ans++;
                it++;
            }
            ans /= 2;
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums({1,2,4,4,3,3,0,9,2,3});
    cout << s.findPairs(nums, 3) << endl;

    return 0;
}