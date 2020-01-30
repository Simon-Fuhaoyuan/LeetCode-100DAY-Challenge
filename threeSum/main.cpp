#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> hashMap; // record each number and its times
        set<int> num_set; // record each number in increasing order
        for (int i = 0; i < nums.size(); ++i) {
            if (hashMap.count(nums[i]))
                hashMap[nums[i]]++;
            else {
                hashMap.insert(make_pair(nums[i], 1));
                num_set.insert(nums[i]);
            }
        }
        // To avoid duplication, I try to store each three-tuple in increasing order
        vector<vector<int>> ans;
        vector<int> tmp;
        int remain = 0;
        for (auto it1 = num_set.begin(); it1 != num_set.end() && *it1 <= 0; ++it1) {
            // according to the increasing order, the first element cannot be over 0.
            tmp.push_back(*it1);
            hashMap[*it1]--;
            for (auto it2 = it1; it2 != num_set.end(); ++it2) {
                if (!hashMap[*it2])
                    continue;
                remain = 0 - *it1 - *it2;
                if (remain < *it2) // the remaining must be the biggest.
                    break;
                tmp.push_back(*it2);
                hashMap[*it2]--;
                if (num_set.count(remain) && hashMap[remain]) {
                    tmp.push_back(remain);
                    ans.push_back(tmp);
                }
                // after find the remain number, restore the tmp vector and hash map.
                tmp.clear();
                tmp.push_back(*it1);
                hashMap[*it2]++;
            }
            hashMap[*it1]++;
            tmp.clear();
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums({-1, 0, 1, 2, -1, -4});
    vector<vector<int>> ans = s.threeSum(nums);

    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < 3; ++j)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
    return 0;
}