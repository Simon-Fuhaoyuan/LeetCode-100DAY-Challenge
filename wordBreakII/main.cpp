#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> mp;
        return helper(s, wordDict, mp);
    }
private:
    vector<string> helper(string s, vector<string>& wordDict, unordered_map<string, vector<string>>& mp) {
        vector<string> ans, tmp;
        if (s.empty())
            return ans;
        if (mp.count(s))
            return mp[s];
        for (int i = 0; i < wordDict.size(); ++i) {
            if (s.substr(0, wordDict[i].length()) == wordDict[i]) {
                tmp = helper(s.substr(wordDict[i].length()), wordDict, mp);
                if (s.length() == wordDict[i].length())
                    ans.push_back(wordDict[i]);
                else {
                    for (int j = 0; j < tmp.size(); ++j)
                        ans.push_back(wordDict[i] + " " + tmp[j]);
                }
            }
        }
        mp[s] = ans;
        return ans;
    }
};

int main() {
    Solution s;
    string str = "pineapplepenapple";
    vector<string> dict({"apple", "pen", "applepen", "pine", "pineapple"});
    vector<string> ans = s.wordBreak(str, dict);
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << endl;
    
    return 0;
}