#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> hashMap(arr.begin(), arr.end());
        int ans = 0;
        for (int i = 0; i < arr.size(); ++i)
            if (hashMap.count(arr[i] + 1))
                ans++;
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> arr({1,3,2,3,5,0});
    cout << s.countElements(arr) << endl;
    return 0;
}