#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int size = A.size();
        int total = 0, max_dq = 0, min_dq = 0;
        int max_seq = 0, min_seq = 0;

        for (int i = 0; i < size; ++i) {
            total += A[i];
            if (i == 0) {
                max_dq = min_dq = A[i];
                max_seq = min_seq = A[i];
                continue;
            }
            max_dq = max(A[i], A[i] + max_dq);
            min_dq = min(A[i], A[i] + min_dq);
            max_seq = max(max_seq, max_dq);
            min_seq = min(min_seq, min_dq);
        }

        total -= min_seq;
        if (total == 0)
            return max_seq;
        return max(total, max_seq);
    }
};
int main()
{
    Solution s;
    vector<int> A({5, -2, 5});
    cout << s.maxSubarraySumCircular(A) << endl;

    return 0;
}
