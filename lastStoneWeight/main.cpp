#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> heap(stones.begin(), stones.end());
        int x, y;
        while (heap.size() > 1) {
            x = heap.top(); heap.pop();
            y = heap.top(); heap.pop();
            if (x > y) {
                x -= y;
                heap.push(x);
            }
        }
        if (heap.empty())
            return 0;
        else
            return heap.top();
    }
};

int main() {
    Solution s;
    vector<int> stones({2,7,4,1,8,1});
    cout << s.lastStoneWeight(stones) << endl;
    return 0;
}