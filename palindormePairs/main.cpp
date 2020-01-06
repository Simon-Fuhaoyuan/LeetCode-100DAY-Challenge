#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include<bits/stdc++.h>
#include <set>
using namespace std;

/**
 * HINT
 * Basic condition: use a hash map to store each str and its idx, for each str, check
 *     whether reverse(str) is in the hash map, note that the idx should be different.
 * Spectial condition: for pairs like 'abcdd' and 'cba', or 'abc' and 'ddcba', they can
 *     concate to palindromes but have different length, use a set to store distinct length
 *     in words and check those substrings. The reason for using set is that set sorts
 *     automatically, and we can traverse the shorter length.
 */

class Solution {
public:
    vector<vector<int> > palindromePairs(vector<string>& words) {
        vector<vector<int> > ans;
        unordered_map<string, int> hashmap;
        set<int> lengths;
        string tmp;
        int length;
        // construct the hash map
        for (int i = 0; i < words.size(); ++i) {
            hashmap.insert(make_pair(words[i], i));
            lengths.insert(words[i].length());
        }
        // traverse words and find reverse
        for (int i = 0; i < words.size(); ++i) {
            tmp = words[i];
            length = words[i].length();
            reverse(tmp.begin(), tmp.end());
            // basic condition
            if (hashmap.count(tmp) && hashmap[tmp] != i)
                ans.push_back({i, hashmap[tmp]});
            // spectial condition
            auto des = lengths.find(length);
            for (auto it = lengths.begin(); it != des; ++it) {
                int len = *it;
                if (valid(tmp, 0, length - len - 1) && hashmap.count(tmp.substr(length - len)))
                    ans.push_back({i, hashmap[tmp.substr(length - len)]});
                if (valid(tmp, len, length - 1) && hashmap.count(tmp.substr(0, len)))
                    ans.push_back({hashmap[tmp.substr(0, len)], i});
            }
        }
        
        return ans;
    }

    bool valid(string str, int start, int end) {
        while (start < end) {
            if (str[start] != str[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<string> words;
    vector<vector<int> > ans;
    words.push_back("abcd");
    words.push_back("dcba");
    words.push_back("lls");
    words.push_back("s");
    words.push_back("sssll");

    ans = s.palindromePairs(words);
    for (int i = 0; i < ans.size(); ++i)
        cout << '[' << ans[i][0] << ", " << ans[i][1] << "] ";
    cout << endl;
}