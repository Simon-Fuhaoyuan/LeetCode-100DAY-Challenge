#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) 
    {
        vector<int> dict(26, 0);
        string::iterator it = text.begin();
        int offset = 0;
        // make the dictionary
        while(it != text.end())
        {
            offset = *it - 'a';
            dict[offset]++;
            it++;
        }
        // search 'b','a','l','o','n' one by one
        int ans = 1e4;
        // b
        if(dict[1] == 0) return 0;
        else if (dict[1] < ans) ans = dict[1];
        // a
        if(dict[0] == 0) return 0;
        else if (dict[0] < ans) ans = dict[0];
        // l
        dict[11] /= 2;
        if(dict[11] == 0) return 0;
        else if (dict[11] < ans) ans = dict[11];
        // o
        dict[14] /= 2;
        if(dict[14] == 0) return 0;
        else if (dict[14] < ans) ans = dict[14];
        // n
        if(dict[13] == 0) return 0;
        else if (dict[13] < ans) ans = dict[13];

        return ans;
    }
};

int main()
{
    Solution s;
    string text = "balloon";
    cout << s.maxNumberOfBalloons(text) << endl;

    return 0;
}