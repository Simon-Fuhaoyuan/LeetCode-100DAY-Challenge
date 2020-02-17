#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty())
			return 0;
		// resize the binary matrix into format of histogram
		int rows = matrix.size();
		int cols = matrix[0].size();
		vector<int> accumulate(cols + 1, 0);
		stack<int> stk;
		int ans = 0, tmp;
		for (int i = 0; i < rows; ++i) {
			stk = stack<int>();
			for (int j = 0; j < cols; ++j)
				accumulate[j] = matrix[i][j] == '1' ? accumulate[j] + 1 : 0;
			// use the same trick for problem "max rectangle in histogram"
			for (int j = 0; j < cols + 1; ++j) {
				if (stk.empty() || accumulate[j] > accumulate[stk.top()])
					stk.push(j);
				else {
					while (!stk.empty() && accumulate[j] <= accumulate[stk.top()]) {
						tmp = stk.top();
						stk.pop();
						ans = max(ans, accumulate[tmp] * (stk.empty() ? j : (j - stk.top() - 1)));
					}
					stk.push(j);
				}
			}
		}
		return ans;
	}
};