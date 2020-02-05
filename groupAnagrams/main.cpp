#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        string mask;
        for (int i = 0; i < 26; ++i)
            mask.push_back(0);
        unordered_map<string, vector<string>> hash_map;
        vector<vector<string>> ans;
        for (auto it = strs.begin(); it != strs.end(); ++it) {
            clear(mask);
            for (int i = 0; i < (*it).length(); ++i)
                mask[(*it)[i] - 'a']++;
            if (hash_map.count(mask))
                hash_map[mask].push_back(*it);
            else {
                vector<string> tmp;
                tmp.push_back(*it);
                hash_map.insert(make_pair(mask, tmp));
            }
        }
        for (auto it = hash_map.begin(); it != hash_map.end(); ++it)
            ans.push_back(it->second);
        return ans;
    }
private:
    void clear(string &mask) {
        for (int i = 0; i < 26; ++i)
            mask[i] = 0;
    }
};

int main() {
    Solution s;
    vector<string> strs({"eat", "tea", "tan", "ate", "nat", "bat"});
    vector<vector<string>> ans = s.groupAnagrams(strs);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j)
            cout << ans[i][j] << ' ';
        cout << endl;
    }

    return 0;
}