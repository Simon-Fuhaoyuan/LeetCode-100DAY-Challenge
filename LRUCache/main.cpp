#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    int capacity;
    int size;
    int least_time;
    int curr_time;
    unordered_map<int, int> cache;
    unordered_map<int, int> time_key;
    unordered_map<int, int> key_time;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->least_time = 0;
        this->curr_time = 0;
    }
    
    int get(int key) {
        if (!cache.count(key))
            return -1;
        curr_time++;
        int last_time = key_time[key];
        key_time[key] = curr_time;
        time_key.erase(last_time);
        time_key[curr_time] = key;
        update_least_time();
        return cache[key];
    }
    
    void put(int key, int value) {
        curr_time++;
        if (cache.count(key)) {
            cache[key] = value;
            int last_time = key_time[key];
            key_time[key] = curr_time;
            time_key.erase(last_time);
            time_key[curr_time] = key;
        }
        else {
            if (least_time == 0)
                least_time = curr_time;
            cache[key] = value;
            key_time[key] = curr_time;
            time_key[curr_time] = key;
            size++;
            if (size > capacity) {
                int del_key = time_key[least_time];
                time_key.erase(least_time);
                key_time.erase(del_key);
                cache.erase(del_key);
            }
        }
        update_least_time();
    }

    void update_least_time() {
        while (!time_key.count(least_time))
            least_time++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */