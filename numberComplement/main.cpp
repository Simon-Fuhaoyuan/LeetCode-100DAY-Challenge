#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int N) {
        vector<int> bits(32, 0);
        for (int i = 0; i < 32; ++i) {
            bits[i] = N % 2;
            N = (N >> 1);
        }
        int first_one_idx = findFirstOne(bits);
        int ans = 0;
        for (int i = 0; i <= first_one_idx; ++i) {
            if (bits[i] == 0) {
                ans += (1 << i);
            }
        }

        return ans;
    }
private:
    int findFirstOne(vector<int>& bits) {
        int index = 0;
        for (int i = 0; i < 32; ++i) {
            if (bits[i] == 1)
                index = i;
        }
        return index;
    }
};

int main() {
    Solution s;
    cout << s.bitwiseComplement(7) << endl;

    return 0;
}