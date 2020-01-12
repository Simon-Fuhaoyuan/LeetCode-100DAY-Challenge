#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int tmp1, tmp2;
        int index1 = 0, index2 = 0;
        while (index1 < version1.length() || index2 < version2.length()) {
            tmp1 = tmp2 = 0;
            while (index1 < version1.length()) {
                index1++;
                if (version1[index1 - 1] != '.')
                    tmp1 = tmp1 * 10 + version1[index1 - 1] - '0';
                else
                    break;
            }
            while (index2 < version2.length()) {
                index2++;
                if (version2[index2 - 1] != '.')
                    tmp2 = tmp2 * 10 + version2[index2 - 1] - '0';
                else
                    break;
            }
            if (tmp1 < tmp2) return -1;
            else if (tmp1 > tmp2) return 1;
        }
        return 0;
    }
};

int main() {
    Solution s;
    cout << s.compareVersion("7.5.2.3", "7.5.3") << endl;

    return 0;
}