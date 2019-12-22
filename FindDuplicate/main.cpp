#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_set<int> set;
        unordered_set<int>::iterator it;
        for (int i = 0; i < nums.size(); ++i)
        {
            it = set.find(nums[i]);
            if (it == set.end())
                set.insert(nums[i]);
            else
                return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    cout << s.containsDuplicate(vec) << endl;
    return 0;
}