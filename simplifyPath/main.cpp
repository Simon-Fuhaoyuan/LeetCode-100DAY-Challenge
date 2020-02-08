#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> dirs;
        string ans;
        string dir;
        int index = 0;
        int length = path.length();
        // record each directory's name
        while (index < length) {
            // '/' can be ignored
            if (path[index] == '/')
                index++;
            // '.' is rather complex, cause it may be "..", "." or ".xxx"(some directory's name)
            else if (path[index] == '.') {
                index++;
                if (index < length && path[index] != '/') {
                    dir.clear();
                    dir.push_back('.');
                    while (index < length && path[index] != '/') {
                        dir.push_back(path[index]);
                        index++;
                    }
                    if (dir == "..") { // return to last directory
                        if (!dirs.empty())
                            dirs.pop();
                    }
                    else // a new directory occurs
                        dirs.push(dir);
                }
            }
            else { // a root's name
                dir.clear();
                while (index < length && path[index] != '/') {
                    dir.push_back(path[index]);
                    index++;
                }
                dirs.push(dir);
            }
        }
        // construct root
        const string slash = "/";
        if (dirs.empty()) {
            ans = slash;
            return ans;
        }
        else while (!dirs.empty()) {
            dir = slash + dirs.top();
            dirs.pop();
            ans = dir + ans;
        }

        return ans;
    }
};

int main() {
    Solution s;
    cout << s.simplifyPath("/../.config") << endl;
    return 0;
}