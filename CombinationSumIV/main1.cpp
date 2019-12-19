#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        queue<int> que;
        // sort nums
        int tmp;
        bool flag = false;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            flag = false;
            for (int j = 0; j < nums.size() - 1; ++j)
                if (nums[j] > nums[j + 1])
                {
                    tmp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = tmp;
                    flag = true;
                }
            if (!flag) break;
        }
        // bfs
        int ans = 0;
        int current = 0;
        for (int i = 0; i < nums.size() && nums[i] <= target; ++i)
            que.push(nums[i]);
        while(!que.empty())
        {
            current = que.front();
            if (current == target)
            {
                ans++;
                que.pop();
            }
            else if (current < target)
            {
                que.pop();
                for (int i = 0; i < nums.size() && current + nums[i] <= target; ++i)
                    que.push(current + nums[i]);
            }
            else
                que.pop();
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v;
    v.push_back(4);
    v.push_back(2);
    v.push_back(1);

    cout << s.combinationSum4(v, 32) << endl;

    return 0;
}