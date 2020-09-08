#include <iostream>
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        bool bits_a[33];
        bool bits_b[33];
        bool bits_c[33];
        getBits(a, bits_a);
        getBits(b, bits_b);
        getBits(c, bits_c);

        bool bit_a, bit_b, bit_c;

        for (int i = 0; i < 32; ++i) {
            bit_a = bits_a[i];
            bit_b = bits_b[i];
            bit_c = bits_c[i];
            if ((bit_a || bit_b) == bit_c)
                continue;
            ans++;
            if (bit_a && bit_b)
                ans++;
        }

        return ans;
    }
private:
    void getBits(int num, bool* bits) {
        for (int i = 0; i < 32; ++i) {
            bits[i] = num % 2;
            num /= 2;
        }
    }
};

int main() {
    int a = 2;
    int b = 6;
    int c = 5;
    Solution s;
    cout << s.minFlips(a, b, c) << endl;
    return 0;
}