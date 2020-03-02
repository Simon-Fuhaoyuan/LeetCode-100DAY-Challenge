#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        vector<int> pri_queue;
        vector<int> ans;
        // construct hash map and store each unique numbers
        for (int i = 0; i < nums.size(); ++i) {
            if (hashMap.count(nums[i]))
                hashMap[nums[i]]++;
            else {
                hashMap.insert(make_pair(nums[i], 1));
                pri_queue.push_back(nums[i]);
            }
        }
        // construct priority queue
        int size = pri_queue.size();
        int hole, tmp, child;
        for (int i = (size - 1) / 2; i >= 0; --i) {
            hole = i;
            tmp = pri_queue[i];
            while (hole * 2 + 1 < size) {
                if (hole * 2 + 2 < size && hashMap[pri_queue[hole * 2 + 2]] > hashMap[pri_queue[hole * 2 + 1]])
                    child = hole * 2 + 2;
                else
                    child = hole * 2 + 1;
                if (hashMap[tmp] < hashMap[pri_queue[child]]) {
                    pri_queue[hole] = pri_queue[child];
                    hole = child;
                }
                else
                    break;
            }
            pri_queue[hole] = tmp;
        }
        // pop for k times
        for (int i = 0; i < k; ++i) {
            ans.push_back(pri_queue[0]);
            pri_queue[0] = pri_queue[--size];
            hole = 0;
            tmp = pri_queue[0];
            // percolate down
            while (hole * 2 + 1 < size) {
                if (hole * 2 + 2 < size && hashMap[pri_queue[hole * 2 + 2]] > hashMap[pri_queue[hole * 2 + 1]])
                    child = hole * 2 + 2;
                else
                    child = hole * 2 + 1;
                if (hashMap[tmp] < hashMap[pri_queue[child]]) {
                    pri_queue[hole] = pri_queue[child];
                    hole = child;
                }
                else
                    break;
            }
            pri_queue[hole] = tmp;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums({1,1,1,2,2,2,2,4,4,3});
    vector<int> ans = s.topKFrequent(nums, 3);
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}