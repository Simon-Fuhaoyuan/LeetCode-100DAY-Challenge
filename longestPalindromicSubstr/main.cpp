#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int length = s.length();
        if (length == 0)
            return ans;
        ans.push_back(s[0]);
        if (length == 1)
            return ans;
    
        bool **dp = new bool*[length];
        for (int i = 0; i < length; ++i)
            dp[i] = new bool[length - i];
        // each single character must be palindromic
        for (int i = 0; i < length; ++i)
            dp[i][0] = true;
        // each two-character tuple is palindromic <=> they are the same
        for (int i = 0; i < length - 1; ++i) {
            dp[i][1] = (s[i] == s[i + 1]);
            if (dp[i][1])
                ans = s.substr(i, 2);
        }
        // traverse all possible substrings
        bool flag_even = true;
        bool flag_odd = true;
        for (int i = 2; i < length; ++i) {
            if (!flag_even && !flag_odd)
                break;
            if (i % 2 == 0) {
                if (!flag_even)
                    continue;
                flag_even = false;
            }
            else {
                if (!flag_odd)
                    continue;
                flag_odd = false;
            }
            for (int start = 0; start < length - i; ++start) {
                dp[start][i] = ((s[start] == s[start + i]) && dp[start + 1][i - 2]);
                if (dp[start][i]) {
                    ans = s.substr(start, i + 1);
                    if (i % 2 == 0)
                        flag_even = true;
                    else
                        flag_odd = true;
                }
            }
        }
        
        return ans;
    }
};

class Solution2 {
public:
    string longestPalindrome(string s) {
        string res;  
        int n=s.size(),maxstart=0,maxlen=1,i=0; 
        if(n<=1){
            return s;
        }
            
        while(i<n){
            int start=i;
            int end=i;   
            
            //even
            while(end+1<n && s[end]==s[end+1]) end ++;
                
            i=end+1;
                
            //odd
            while(start-1>=0 && end+1<n && s[start-1]==s[end+1]) end ++,start--;
            
            //Maxlen
            int currlen=end-start+1;
            if(currlen>maxlen){
                maxstart=start;
                maxlen=currlen;
            }        
        }
            
        res=s.substr(maxstart,maxlen);   
        return res;
        
    }
};

int main() {
    Solution s;
    cout << s.longestPalindrome("babad") << endl;

    return 0;
}