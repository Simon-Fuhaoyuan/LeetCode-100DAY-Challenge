#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int, vector<char> > letter_map;
        // construct the letter_map
        letter_map.insert(make_pair(2, vector<char>({'a', 'b', 'c'})));
        letter_map.insert(make_pair(3, vector<char>({'d', 'e', 'f'})));
        letter_map.insert(make_pair(4, vector<char>({'g', 'h', 'i'})));
        letter_map.insert(make_pair(5, vector<char>({'j', 'k', 'l'})));
        letter_map.insert(make_pair(6, vector<char>({'m', 'n', 'o'})));
        letter_map.insert(make_pair(7, vector<char>({'p', 'q', 'r', 's'})));
        letter_map.insert(make_pair(8, vector<char>({'t', 'u', 'v'})));
        letter_map.insert(make_pair(9, vector<char>({'w', 'x', 'y', 'z'})));
        // traverse the digits
        vector<string> ans;
        string tmp;
        int length = digits.length();
        int *index = new int[length];
        for (int i = 0; i < length; ++i)
            index[i] = 0;
        if (digits.length() == 0) return ans;
        while (index[0] < letter_map[digits[0] - '0'].size()) {
            tmp.clear();
            for (int i = 0; i < length; ++i)
                tmp.push_back(letter_map[digits[i] - '0'][index[i]]);
            ans.push_back(tmp);
            index[length - 1]++;
            for (int i = length - 1; i > 0; --i) {
                if (index[i] == letter_map[digits[i] - '0'].size()) {
                    index[i] = 0;
                    index[i - 1]++;
                }
                else
                    break;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    string digits = "23";
    vector<string> ans = s.letterCombinations(digits);

    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
    cout << endl;
}