#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        unordered_map<int, int> m;
        return dfs(nums, target, m);
    }
    
    int dfs(vector<int>& nums, int target, std::unordered_map<int, int>& m)
    {
        if(target < 0)
            return 0;
        
        if(target == 0)
            return 1;
        
        auto it = m.find(target);
        if(it != m.end())
            return it->second;
        
        int res = 0;
        for(int num : nums)
            res += dfs(nums, target - num, m);
        
        return m[target] = res;
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