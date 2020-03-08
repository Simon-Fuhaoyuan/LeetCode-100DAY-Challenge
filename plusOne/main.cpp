#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int idx = digits.size() - 1;
        bool carry = true;
        while (idx >= 0 && carry) {
            carry = false;
            if (digits[idx] == 9) {
                digits[idx] = 0;
                carry = true;
                idx--;
            }
            else
                digits[idx]++;
        }
        if (carry)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};