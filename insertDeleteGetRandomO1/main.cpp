#include <iostream>
#include <unordered_map>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

class RandomizedSet {
private:
    unordered_map<int, int> set;
    vector<int> nums;
    int size;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        size = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (set.count(val))
            return false;
        set[val] = size;
        if (nums.size() == size)
            nums.push_back(val);
        else
            nums[size] = val;
        size++;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!set.count(val))
            return false;
        int last = nums[size - 1];
        int rm_index = set[val];
        nums[rm_index] = last;
        set[last] = rm_index;
        size--;
        set.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if (size == 0)
            return -1;
        int index = rand() % size;
        return nums[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */