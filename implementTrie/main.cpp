#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    vector<Node*> children;
    bool finish;
    Node() {children = vector<Node*>(26, NULL); finish = false;}
};

class Trie {
private:
    Node *root;
    Node *tmp;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        tmp = root;
        for (int i = 0; i < word.length(); ++i) {
            if (!tmp->children[word[i] - 'a'])
                tmp->children[word[i] - 'a'] = new Node();
            tmp = tmp->children[word[i] - 'a'];
        }
        tmp->finish = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        tmp = root;
        for (int i = 0; i < word.length(); ++i) {
            if (!tmp->children[word[i] - 'a'])
                return false;
            tmp = tmp->children[word[i] - 'a'];
        }
        return tmp->finish;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        tmp = root;
        for (int i = 0; i < prefix.length(); ++i) {
            if (!tmp->children[prefix[i] - 'a'])
                return false;
            tmp = tmp->children[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    Trie *obj = new Trie();
    obj->insert("apple");
    cout << obj->search("apple") << endl;
    cout << obj->startsWith("app") << endl;
    cout << obj->search("app") << endl;
    obj->insert("app");
    cout << obj->search("app") << endl;
    return 0;
}