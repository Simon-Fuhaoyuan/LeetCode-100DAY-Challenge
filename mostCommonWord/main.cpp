#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        set<string> banned_set;
        for (int i = 0; i < banned.size(); ++i)
            banned_set.insert(banned[i]);
        
        string tmp;
        unordered_map<string, int> word_map;
        unordered_map<string, int>::iterator it;
        for (int i = 0; i < paragraph.length(); ++i) {
            if (isLetter(paragraph[i])) {
                tmp.clear();
                while(i < paragraph.length() && isLetter(paragraph[i])) {
                    if (isUppercase(paragraph[i]))
                        paragraph[i] -= 'A' - 'a';
                    tmp.push_back(paragraph[i]);
                    i++;
                }
                it = word_map.find(tmp);
                if (it == word_map.end())
                    word_map.insert(make_pair(tmp, 1));
                else
                    it->second++;
            }
        }
        // to save space, use banned to store sorted word list
        banned.clear();
        vector<int> times;
        it = word_map.begin();
        int i;
        while (it != word_map.end()) {
            for (i = 0; i < times.size() && times[i] > it->second; ++i)
                continue;
            banned.insert(banned.begin() + i, it->first);
            times.insert(times.begin() + i, it->second);
            it++;
        }
        // check each string and return
        for (i = 0; i < banned.size(); ++i)
            if (banned_set.find(banned[i]) == banned_set.end())
                return banned[i];
        return "";
    }
private:
    bool isLetter(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
    bool isUppercase(char c) {
        return c >= 'A' && c <= 'Z';
    }
};

int main() {
    Solution s;
    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned({"hit"});

    cout << s.mostCommonWord(paragraph, banned) << endl;
    return 0;
}