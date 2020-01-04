#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MagicDictionary {
private:
    vector<string> dict;

public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        dict.clear();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        this->dict = dict;
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        int num = dict.size();
        int diff = 0;
        for (int i = 0; i < num; ++i)
        {
            if (word.length() != dict[i].length())
                continue;
            diff = 0;
            for (int j = 0; j < word.length(); ++j)
            {
                if (word[j] != dict[i][j])
                {
                    diff++;
                    if (diff > 1) break;
                }
            }
            if (diff == 1) return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */

int main()
{
    MagicDictionary *obj = new MagicDictionary();
    vector<string> input;
    input.push_back("hello");
    input.push_back("leetcode");
    obj->buildDict(input);

    cout << obj->search("helll") << endl;
    cout << obj->search("leetcoded") << endl;
}