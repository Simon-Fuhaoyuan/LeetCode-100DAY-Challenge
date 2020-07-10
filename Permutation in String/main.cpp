class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length())
            return false;
        int len1 = s1.length(), len2 = s2.length();
        vector<int> s1_stat(26, 0);
        vector<int> s2_stat(26, 0);
        for (int i = 0; i < len1; ++i) {
            s1_stat[s1[i] - 'a']++;
            s2_stat[s2[i] - 'a']++;
        }
        int idx = len1;
        if (check_same(s1_stat, s2_stat))
            return true;
        while (idx < len2) {
            s2_stat[s2[idx] - 'a']++;
            s2_stat[s2[idx - len1] - 'a']--;
            if (check_same(s1_stat, s2_stat))
                return true;
            idx++;
        }
        return false;
    }
private:
    bool check_same(vector<int>& s1, vector<int>& s2) {
        for (int i = 0; i < 26; ++i)
            if (s1[i] != s2[i])
                return false;
        return true;
    }
};
