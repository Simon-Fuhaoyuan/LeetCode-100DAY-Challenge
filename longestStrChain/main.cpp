#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
private:
    const int MAX_LENTH = 16;
public:
    int longestStrChain(vector<string>& words) {
        vector<vector<string>> words_class(MAX_LENTH, vector<string>());
        unordered_map<string, int> chain_length;
        // construct words_class, classify each string by its length
        for (int i = 0; i < words.size(); ++i) {
            chain_length.insert(make_pair(words[i], 1));
            words_class[words[i].length() - 1].push_back(words[i]);
        }
        // construct chain_length, starting from shorter strings
        for (int i = 0; i < MAX_LENTH - 1; ++i) {
            if (words_class[i].empty() || words_class[i + 1].empty())
                continue;
            for (int j = 0; j < words_class[i].size(); ++j)
                for (int k = 0; k < words_class[i + 1].size(); ++k) {
                    if (isPredecessor(words_class[i][j], words_class[i + 1][k]) && 
                      chain_length[words_class[i + 1][k]] <= chain_length[words_class[i][j]])
                        chain_length[words_class[i + 1][k]] = chain_length[words_class[i][j]] + 1;
                }
        }
        // find the longest
        int ans = 0;
        string max;
        for (auto it = chain_length.begin(); it != chain_length.end(); ++it)
            if (it->second > ans) {
                ans = it->second;
                max = it->first; // for debug
            }
        
        return ans;
    }
private:
    bool isPredecessor(const string &first, const string &second) {
        if (second.length() - first.length() != 1)
            return false;
        int length = first.length();
        int i = 0, j = 0; // i, j for index of first, second
        for (; i < length; ++i && ++j) {
            if (first[i] != second[j]) {
                if (i == j) {
                    j++;
                    if (first[i] != second[j])
                        return false;
                }
                else
                    return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    vector<string> words({"qyssedya","pabouk","mjwdrbqwp","vylodpmwp","nfyqeowa","pu","paboukc","qssedya","lopmw","nfyqowa","vlodpmw","mwdrqwp","opmw","qsda","neo","qyssedhyac","pmw","lodpmw","mjwdrqwp","eo","nfqwa","pabuk","nfyqwa","qssdya","qsdya","qyssedhya","pabu","nqwa","pabqoukc","pbu","mw","vlodpmwp","x","xr"});

    cout << s.longestStrChain(words) << endl;
    return 0;
}