#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        // construct the dictionary
        vector<int> dic(26, 0);
        int len_p = p.length();
        for (int i = 0; i < len_p; ++i)
            dic[p[i] - 'a']++;
        // iterate string s
        int start = 0, end = 0;
        while (end < s.length()) {
            // a valid char 
            if (dic[s[end] - 'a'] > 0) {
                dic[s[end] - 'a']--;
                if (success(dic))
                    ans.push_back(end - len_p + 1);
                end++;
            }
            // this char is not in dictionary
            else {
                // delete characters before this char
                while (start < end && dic[s[end] - 'a'] == 0) {
                    dic[s[start] - 'a']++;
                    start++;
                }
                // if start == end, but this char still not exists in dictionary
                // it means this character is not in p, then move on
                if (dic[s[end] - 'a'] == 0) {
                    start++;
                    end++;
                }
            }
        }
        return ans;
    }
private:
    bool success(vector<int>& dic) {
        for (int i = 0; i < 26; ++i)
            if (dic[i] > 0)
                return false;
        return true;
    }
};

int main() {
    Solution s;
    string str = "abaacbabc";
    string p = "abc";
    vector<int> ans = s.findAnagrams(str, p);
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}