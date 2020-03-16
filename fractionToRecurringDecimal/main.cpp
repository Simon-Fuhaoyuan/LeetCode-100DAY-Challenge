#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
        string ans;
        bool negative = false;
        long long int num = numerator, den = denominator;
        if (numerator < 0) {
            num *= -1;
            negative = !negative;
        }
        if (denominator < 0) {
            den *= -1;
            negative = !negative;
        }
        long long int intPart = num / den;
        long long int remainder = num - intPart * den;
        if (remainder == 0) {
            if (negative)
                ans = "-";
            ans += to_string(intPart);
            return ans;
        }
        unordered_map<long long int, int> hashMap;
        int index = 0, bit;
        while (remainder != 0) {
            remainder *= 10;
            if (hashMap.count(remainder)) {
                ans.insert(ans.begin() + hashMap[remainder], '(');
                ans.push_back(')');
                break;
            }
            hashMap[remainder] = index;
            bit = remainder / den;
            ans.push_back('0' + bit);
            remainder -= bit * den;
            index++;
        }
        ans = to_string(intPart) + "." + ans;
        if (negative)
            ans.insert(ans.begin(), '-');
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.fractionToDecimal(-22, -1) << endl;
    return 0;
}