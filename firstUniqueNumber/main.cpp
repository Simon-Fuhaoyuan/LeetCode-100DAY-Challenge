#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

class FirstUnique {
private:
    int index;
    unordered_set<int> all_nums;
    unordered_map<int, int> num_index;
    unordered_map<int, int> index_num;
    set<int> uniqueIndex;
public:
    FirstUnique(vector<int>& nums) {
        index = 0;
        while (index < nums.size()) {
            deal_with_num(nums[index]);
            index++;
        }
    }
    
    int showFirstUnique() {
        if (uniqueIndex.empty())
            return -1;
        return index_num[*(uniqueIndex.begin())];
    }
    
    void add(int value) {
        deal_with_num(value);
    }

private:
    void deal_with_num(int num) {
        int tmp_idx;
        if (all_nums.count(num) && num_index.count(num)) {
            tmp_idx = num_index[num];
            num_index.erase(num);
            index_num.erase(tmp_idx);
            uniqueIndex.erase(tmp_idx);
        }
        else if (!all_nums.count(num)) {
            all_nums.insert(num);
            num_index[num] = index;
            index_num[index] = num;
            uniqueIndex.insert(index);
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */