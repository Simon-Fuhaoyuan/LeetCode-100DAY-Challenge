// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1;
        int end = n;
        int test = start + (end - start) / 2;
        while (start < end) {
            if (isBadVersion(test))
                end = test;
            else
                start = test + 1;
            test = start + (end - start) / 2;
        }
        return test;
    }
};
