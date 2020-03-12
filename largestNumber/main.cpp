#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.empty())
            return "";
        // sort by new rule
        sort(nums.begin(), nums.end(), [](int x, int y) {
            return to_string(x) + to_string(y) > to_string(y) + to_string(x); 
        });
        // combine to string
        string ans = "";
        for (int i = 0; i < nums.size(); ++i)
            ans += to_string(nums[i]);
        // change to valid
        ans = ans[0] == '0' ? "0" : ans;
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums({0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});
    cout << s.largestNumber(nums) << endl;
    return 0;
}