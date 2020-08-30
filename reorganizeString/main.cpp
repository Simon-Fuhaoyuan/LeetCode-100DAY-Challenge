#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * HINT: Greedy Algorithm
 */

class Solution {
public:
    string reorganizeString(string S) {
        // Construct alpha dict
        vector<int> dict(26, 0);
        int length = S.length();
        for (int i = 0; i < length; ++i) {
            dict[S[i] - 'a']++;
        }

        string ans = "";
        int ignore_idx = -1;
        int max_freq_idx = -1;
        for (int i = 0; i < length; ++i) {
            max_freq_idx = get_max_frequency_idx(dict, ignore_idx);
            if (max_freq_idx == -1)
                return "";
            dict[max_freq_idx]--;
            ans += (char)('a' + max_freq_idx);
            ignore_idx = max_freq_idx;
        }

        return ans;
    }

private:
    bool helper(vector<int>& dict, string& ans, int depth, const int length) {
        if (depth == length)
            return true;
        for (int i = 0; i < 26; ++i) {
            if (dict[i] > 0 && (depth == 0 || i != *(ans.end() - 1) - 'a')) {
                dict[i]--;
                ans += (char)('a' + i);
                if (helper(dict, ans, depth + 1, length))
                    return true;
                dict[i]++;
                ans.erase(ans.end() - 1);
            }
        }
        return false;
    }

    int get_max_frequency_idx(vector<int>& dict, int ignore_idx = -1) {
        int max_frequency_idx = -1;
        int max_frequency = 0;
        for (int i = 0; i < 26; ++i) {
            if (i != ignore_idx && dict[i] > max_frequency) {
                max_frequency_idx = i;
                max_frequency = dict[i];
            }
        }

        return max_frequency_idx;
    }
};

int main() {
    Solution s;
    string str = "lkllgpllgqlywlllptl";
    cout << s.reorganizeString(str) << endl;

    return 0;
}