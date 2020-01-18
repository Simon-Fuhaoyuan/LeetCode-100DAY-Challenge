#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        partition(s, ans);

        return ans;
    }

private:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    void partition(string s, vector<vector<string>> &ans) {
        int idx = 0;
        vector<vector<string>> sub_ans;
        vector<string> tmp;
        for (; idx < s.length(); ++idx) 
            if (isPalindrome(s.substr(0, idx + 1))) {
                tmp.clear();
                if (idx == s.length() - 1) {
                    tmp.push_back(s);
                    ans.push_back(tmp);
                }
                else {
                    sub_ans.clear();
                    partition(s.substr(idx + 1), sub_ans);
                    for (int i = 0; i < sub_ans.size(); ++i) {
                        sub_ans[i].insert(sub_ans[i].begin(), s.substr(0, idx + 1));
                        ans.push_back(sub_ans[i]);
                    }
                }
            }
    }
};

// another solution from Discussion, which is better
class SolutionDFS {
public:
	vector<vector<string>> ans;
	vector<string> path;
	bool ispl(string s){
		if(s.size()==0 || s.size()==1) return true;
		int start=0;
		int end=s.size()-1;
		while(start<end){
			if(s[start]!=s[end]) return false;
			start++;
			end--;
		}
		return true;
	}
	void dfs(string& s, int index,vector<string>& path){
		if(index==s.size()){
			ans.push_back(path);
			return;
		}
		if(index>s.size()) return;
		for(int i=index;i<s.size();i++){
			string temp=s.substr(index,i-index+1);
			if(ispl(temp)){
				path.push_back(temp);
				dfs(s,i+1,path);
				path.pop_back();
			}
		}
	}
	vector<vector<string>> partition(string s) {
		dfs(s,0,path);
		return ans;
	}
};

int main() {
    string str = "aab";
    Solution s;
    vector<vector<string>> ans = s.partition(str);

    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j)
            cout << ans[i][j] << ' ';
        cout << endl;
    }

    return 0;
}