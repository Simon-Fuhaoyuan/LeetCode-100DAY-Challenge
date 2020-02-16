#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> target;
        queue<int> positions;
        int idx = 0, length = s.length();
        int min_len = length + 1, start = -1;
        int tmp_start;
        int cnt = 0;
        bool flag;
        // construct letters
        for (int i = 0; i < t.length(); ++i) {
            if (target.count(t[i]))
                target[t[i]]++;
            else
                target.insert(make_pair(t[i], 1));
        }
        // iterate string s
        while (idx < length) {
            if (target.find(s[idx]) == target.end()) {
                idx++;
                continue;
            }
            flag = false;
            positions.push(idx);
            if (--target[s[idx]] >= 0)
                cnt++;
            while (cnt == t.length()) {
                flag = true;
                tmp_start = positions.front();
                positions.pop();
                if (++target[s[tmp_start]] > 0)
                    cnt--;
            }
            if (flag && idx - tmp_start + 1 < min_len) {
                min_len = idx - tmp_start + 1;
                start = tmp_start;
            }
            idx++;
        }
        if (start == -1) // no answer
            return "";
        else
            return s.substr(start, min_len);
    }
};

int main() {
    Solution s;
    cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
    return 0;
}