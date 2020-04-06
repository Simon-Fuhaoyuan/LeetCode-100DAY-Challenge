#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        visited.insert(n);
        vector<int> digits;
        while (true) {
            while (n > 0) {
                digits.push_back(n % 10);
                n /= 10;
            }
            for (int i = 0; i < digits.size(); ++i)
                n += digits[i] * digits[i];
            digits.clear();
            if (n == 1)
                return true;
            else if (visited.count(n))
                break;
            else
                visited.insert(n);
        }
        return false;
    }
};

int main() {
    Solution s;
    cout << s.isHappy(19) << endl;
    return 0;
}