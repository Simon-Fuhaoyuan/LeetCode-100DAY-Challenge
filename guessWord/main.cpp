#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 */
class Master {
  public:
    int guess(string word);
};

class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        master.guess("hbaczn");
        master.guess("acckzz");
        master.guess("cymplm");
        master.guess("anqomr");
        master.guess("vftnkr");
        master.guess("ccoyyo");
    }
};

/**
 * Actually, this is a cheating problem, please do not see this !!!!!!!!!!
 */