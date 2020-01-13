#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        map<char, char> pat; // each pattern char maps to which word char
        vector<char> wor(26, '0'); // each word char maps from which pattern char
        int len = pattern.length();
        bool success;
        vector<string> ans;
        for (int i = 0; i < len; ++i)
            if (pat.find(pattern[i]) == pat.end())
                pat.insert(make_pair(pattern[i], '0'));
        
        for (int i = 0; i < words.size(); ++i) {
            // clear two maps
            for (int j = 0; j < 26; ++j)
                wor[j] = '0';
            for (auto j = pat.begin(); j != pat.end(); ++j)
                j->second = '0';
            // check each character
            success = true;
            for (int j = 0; j < len; ++j) {
                if (pat[pattern[j]] == '0' && wor[words[i][j] - 'a'] == '0') {
                    pat[pattern[j]] = words[i][j];
                    wor[words[i][j] - 'a'] = pattern[j];
                }
                else if (pat[pattern[j]] == words[i][j] && wor[words[i][j] - 'a'] == pattern[j])
                    continue;
                else {
                    success = false;
                    break;
                }
            }
            if (success)
                ans.push_back(words[i]);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> input({"abc","deq","mee","aqq","dkd","ccc"});
    string pattern = "abb";
    vector<string> ans = s.findAndReplacePattern(input, pattern);

    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
    cout << endl;

    return 0;
}