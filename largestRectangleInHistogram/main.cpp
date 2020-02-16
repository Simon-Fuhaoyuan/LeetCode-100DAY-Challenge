#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**HINT
 * Use a stack, all elements in it are in increasing order.
 * When face a smaller element, trigger all bigger elements in stack to pop and calculate.
 * Note that the smallest element will never be popped.
 * Elements in the stack satisfies: each height between two adjacent element in stack is higher than the right one, 
 *      and the right one is strict bigger than the left one.(This is the most important)
 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> st;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int cur = st.top(); st.pop();
                res = max(res, heights[cur] * (st.empty() ? i : (i - st.top() - 1)));
            }
            st.push(i);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums({2,1,5,6,2,3});
    cout << s.largestRectangleArea(nums) << endl;
    return 0;
}