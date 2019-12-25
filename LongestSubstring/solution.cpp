#include <string>
#include <unordered_set>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.length();
        int i = 0, j = 0; // start and end
        unordered_map<char, int> sub; // substrings
        unordered_map<char, int>::const_iterator found;
        int max = 0;
        while(i < size && j < size)
        {
            found = sub.find(s[j]);
            if (found == sub.end())
            {
                sub.insert(s[j]);
                j++;
                if (j - i > max) max = j - i;
            }
            else
            {
                sub.erase(sub.begin());
                i++;
            }
        }
        return max;
    }
};
