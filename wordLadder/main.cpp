#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<int> lengths;
        queue<string> words;
        words.push(beginWord);
        lengths.push(1);
        string tmp;
        int len;
        char c;
        while (!words.empty()) {
            tmp = words.front(); words.pop();
            len = lengths.front(); lengths.pop();
            len++;
            if (wordSet.empty())
                break;
            for (int i = 0; i < tmp.length(); ++i) {
                c = tmp[i];
                for (int j = 0; j < 26; ++j) {
                    if ('a' + j == c)
                        continue;
                    tmp[i] = 'a' + j;
                    if (wordSet.count(tmp)) {
                        if (tmp == endWord)
                            return len;
                        words.push(tmp);
                        lengths.push(len);
                        wordSet.erase(tmp);
                    }
                }
                tmp[i] = c;
            }
        }
        return 0;
    }
};

int main() {
    Solution s;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList({"hot","dot","dog","lot","log","cog"});
    cout << s.ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}