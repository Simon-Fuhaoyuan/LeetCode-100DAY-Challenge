#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        // assume (A+Bi) * (C+Di) = (E + Fi)
        int A, B, C, D;
        int i = 0;
        string sub;
        // parse A+Bi
        while(a[i] != '+')
            sub += a[i++];
        A = stoi(sub);
        sub.clear();
        i++;
        while(a[i] != 'i')
            sub += a[i++];
        B = stoi(sub);
        sub.clear();
        // parse C+Di
        i = 0;
        while(b[i] != '+')
            sub += b[i++];
        C = stoi(sub);
        sub.clear();
        i++;
        while(b[i] != 'i')
            sub += b[i++];
        D = stoi(sub);
        sub.clear();
        
        return to_string(A * C - B * D) + '+' + to_string(A * D + B * C) + 'i';
    }
};

int main()
{
    Solution s;
    string a = "1+1i";
    string b = "1+1i";
    
    cout << s.complexNumberMultiply(a, b) << endl;
    return 0;
}