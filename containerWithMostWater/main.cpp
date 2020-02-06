#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0, tmp;
        int head = 0, tail = height.size() - 1;
        while (head < tail) {
            tmp = min(height[tail], height[head]);
            if (tmp * (tail - head) > max)
                max = tmp * (tail - head);
            while (min(height[tail], height[head]) <= tmp && head < tail) {
                if (height[tail] <= height[head])
                    tail--;
                else
                    head++;
            }
        }

        return max;
    }
private:
    int min(int x, int y) {
        return x < y ? x : y;
    }
};

int main() {
    Solution s;
    vector<int> height({1,8,6,2,5,4,8,3,7});
    cout << s.maxArea(height) << endl;

    return 0;
}