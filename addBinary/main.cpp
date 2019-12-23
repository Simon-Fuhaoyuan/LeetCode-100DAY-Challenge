#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) 
    {
        string ans;
        int pos_a = a.length() - 1;
        int pos_b = b.length() - 1;
        bool curr_a, curr_b;
        bool carry = false;

        while (pos_a >= 0 || pos_b >= 0)
        {
            curr_a = curr_b = false;
            if (pos_a >= 0)
                curr_a = a[pos_a] == '1' ? true : false;
            if (pos_b >= 0)
                curr_b = b[pos_b] == '1' ? true : false;
            if (curr_a && curr_b)
            {
                if (carry)
                    ans.insert(ans.begin(), '1');
                else
                    ans.insert(ans.begin(), '0');
                carry = true;
            }
            else if (curr_a || curr_b)
            {
                if (carry)
                {
                    ans.insert(ans.begin(), '0');
                    carry = true;
                }
                else
                {
                    ans.insert(ans.begin(), '1');
                    carry = false;
                }
            }
            else
            {
                if (carry)
                    ans.insert(ans.begin(), '1');
                else
                    ans.insert(ans.begin(), '0');
                carry = false;
            }
            pos_a--;
            pos_b--;
        }

        if (carry)
            ans.insert(ans.begin(), '1');
        
        return ans;
    }
};

int main()
{
    Solution s;
    string a = "1010";
    string b = "1011";

    cout << s.addBinary(a, b) << endl;
    return 0;
}