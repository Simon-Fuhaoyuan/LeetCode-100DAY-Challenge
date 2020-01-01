#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string S)
    {
        string buffer;
        string ans;
        int length = S.length();
        int buffer_len = 0;
        for (int i = 0; i < length; ++i)
            if ((S[i] >= 'a' && S[i] <= 'z') || (S[i] >= 'A' && S[i] <= 'Z'))
            {
                buffer.push_back(S[i]);
                buffer_len++;
            }
        for (int i = 0, j = 0; i < length; ++i)
        {
            if (!((S[i] >= 'a' && S[i] <= 'z') || (S[i] >= 'A' && S[i] <= 'Z')))
                ans.push_back(S[i]);
            else
            {
                ans.push_back(buffer[buffer_len - j - 1]);
                j++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string str = "a-bC-dEf-ghIj";
    cout << s.reverseOnlyLetters(str) << endl;

    return 0;
}