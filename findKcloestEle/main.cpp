#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int start = 0, end = arr.size() - 1, mid;
        while (start < end) {
            mid = (start + end) / 2;
            if (arr[mid] > x)
                end = mid - 1;
            else if (arr[mid] < x)
                start = mid + 1;
            else
                start = end = mid;
        }
        if (arr[start] <= x)
            end = start + 1;
        else
            end = start--;
        while (ans.size() < k) {
            if (start >= 0 && end < arr.size()) {
                if (x - arr[start] <= arr[end] - x){
                    ans.insert(ans.begin(), arr[start]);
                    start--;
                }
                else {
                    ans.push_back(arr[end]);
                    end++;
                }
            }
            else if (start >= 0) {
                ans.insert(ans.begin(), arr[start]);
                start--;
            }
            else {
                ans.push_back(arr[end]);
                end++;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums({1,2,3,4,5});
    int k = 4;
    int x = 3;
    vector<int> ans = s.findClosestElements(nums, k, x);
    for (int i = 0; i < k; ++i)
        cout << ans[i] << ' ';
    cout << endl;
}