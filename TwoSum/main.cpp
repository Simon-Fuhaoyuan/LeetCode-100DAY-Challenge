#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ans;
        unordered_map<int, int> ump;
        unordered_map<int, int>::iterator it;
        // make hash map
        for (int i = 0; i < nums.size(); ++i)
        {
            it = ump.find(nums[i]);
            if (it != ump.end()) // there are two same numbers
            {
                if (2 * nums[i] == target) // they are the answer
                {
                    ans.push_back(it->second);
                    ans.push_back(i);
                    return ans;
                }
                else // they cannot be used since there is only one answer
                {
                    ump.erase(it);
                    continue;
                }
            }
            ump.insert(make_pair(nums[i], i));
        }

        // find target
        for (int i = 0; i < nums.size(); ++i)
        {
            int val = target - nums[i];
            it = ump.find(val);
            if (it != ump.end() && it->second != i) // prevent two same numbers
            {
                ans.push_back(i);
                ans.push_back(it->second);
                return ans;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(7);
    arr.push_back(11);
    arr.push_back(15);

    vector<int> ans = s.twoSum(arr, 9);
    if (ans.size() > 0)
        cout << ans[0] << ' ' << ans[1] << endl;
    else
        cout << endl;

    return 0;
}