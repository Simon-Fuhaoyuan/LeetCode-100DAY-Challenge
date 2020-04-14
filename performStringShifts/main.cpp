#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int move = 0;
        for (int i = 0; i < shift.size(); ++i) {
            if (shift[i][0] == 0)
                move += shift[i][1];
            else
                move -= shift[i][1];
        }
        if (move == 0)
            return s;
        else if (move > 0) {
            move %= s.length();
            return s.substr(move) + s.substr(0, move);
        }
        else {
            move = (-1 * move) % s.length();
            return s.substr(s.length() - move) + s.substr(0, s.length() - move);
        }
    }
};

int main() {
    Solution s;
    string str = "abcdefg";
    vector<vector<int>> shift({{1,1},{1,1},{0,2},{1,3}});
    cout << s.stringShift(str, shift) << endl;
    return 0;
}