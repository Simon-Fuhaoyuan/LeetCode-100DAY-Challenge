#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> ans(K, vector<int>(2, 0));
        int size = 0;
        while (size < K)
            push(ans, points[size], size++);
        for (; size < points.size(); ++size)
            popAndPush(ans, points[size], K);

        return ans;
    }

    void push(vector<vector<int>>& ans, vector<int>& point, int size) {
        int dist = distance(point);
        while (size > 0 && dist > distance(ans[(size - 1) / 2])) {
            ans[size] = ans[(size - 1) / 2];
            size = (size - 1) / 2;
        }
        ans[size] = point;
    }

    void popAndPush(vector<vector<int>>& ans, vector<int>& point, int size) {
        int dist = distance(point);
        if (dist > distance(ans[0]))
            return;
        int index = 0;
        vector<int> tmp;
        bool right_child = false;
        while (index * 2 + 1 < size) {
            tmp = ans[index * 2 + 1];
            right_child = false;
            if (index * 2 + 2 < size && distance(tmp) < distance(ans[index * 2 + 2])) {
                tmp = ans[index * 2 + 2];
                right_child = true;
            }
            if (distance(tmp) > dist) {
                ans[index] = tmp;
                index = right_child ? index * 2 + 2 : index * 2 + 1;
            }
            else
                break;
        }
        ans[index] = point;
    }

    int distance(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }
};

int main()
{
    Solution s;
    vector<int> A({5, -2, 5});
    cout << s.maxSubarraySumCircular(A) << endl;

    return 0;
}
