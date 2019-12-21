#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        else{
            long long rev=0;
            int last, num=x;
            
            while(num!=0){
                last=num%10;
                rev=(rev*10)+last;
                num=num/10;
            }
            if(x==rev)
                return true;
            else
                return false;
        }
        
    }
};