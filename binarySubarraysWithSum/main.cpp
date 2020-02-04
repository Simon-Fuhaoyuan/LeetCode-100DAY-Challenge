#include <iostream>
#include <vector>
using namespace std;

/**HINT
 * Each time we get a range, we need to calculate how many continuous zeros before the first valid 1, 
 * and how many continuous zeros after the last valid 1, then calculate (1 + pre_zero)*(1 + post_zero)
 * is the number of possible subarrays of these 1s.
 * However, if S is 0, the condition is different, we just focus on how many continuous 0s, and use some
 * easy-understanding tricks to calculate the final results.
 */

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        if (S == 0)
            return numSubarrayWith0(A);
        int ans = 0;
        int tmp = 0;
        int head = 0, tail = 0;
        int pre_zero = 0, post_zero = 0;
        int size = A.size();
        // find the first subarray
        while (tail < size && tmp < S) {
            if (A[tail])
                tmp++;
            if (tmp == S) break;
            tail++;
        }
        // no subarray
        if (tail == size)
            return 0;
        // normal scenario
        while (tail < size) {
            pre_zero = 0;
            post_zero = 0;
            while (!A[head]) {
                pre_zero++;
                head++;
            }
            head++; // delete a 1
            tail++; // start to find a new 1
            while (tail < size && !A[tail]) {
                tail++;
                post_zero++;
            }
            ans += (1 + pre_zero) * (1 + post_zero);
        }

        return ans;
    }
private:
    int numSubarrayWith0(vector<int> &A) {
        int ans = 0;
        int continuous_0 = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i])
                continuous_0 = 0;
            else
                ans += ++continuous_0;
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> A({0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0});
    vector<int> B({1,0,1,0,1});
    cout << s.numSubarraysWithSum(B, 2) << endl;

    return 0;
}