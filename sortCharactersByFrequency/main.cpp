#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        for (int i = 0; i < s.length(); ++i) {
            if (mp.count(s[i]))
                mp[s[i]]++;
            else
                mp[s[i]] = 1;
        }
        map<char, int>::iterator it, max_it;
        string ans;
        while (!mp.empty()) {
            it = mp.begin();
            int max = 0;
            while (it != mp.end()) {
                if (it->second > max) {
                    max = it->second;
                    max_it = it;
                }
                it++;
            }
            for (int i = 0; i < max; ++i)
                ans.push_back(max_it->first);
            mp.erase(max_it->first);
        }

        return ans;
    }
};
