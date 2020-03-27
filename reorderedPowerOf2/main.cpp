#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        unordered_set<string> dict;
        string nums(10, 0);
        int power;
        for (int i = 0; i < 31; ++i) {
            power = (1 << i);
            while (power > 0) {
                nums[power % 10]++;
                power /= 10;
            }
            dict.insert(nums);
            for (int j = 0; j < 10; ++j)
                nums[j] = 0;
        }
        while (N > 0) {
            nums[N % 10]++;
            N /= 10;
        }
        if (dict.count(nums))
            return true;
        return false;
    }
};

int main() {
    Solution s;
    cout << s.reorderedPowerOf2(46) << endl;
    return 0;
}