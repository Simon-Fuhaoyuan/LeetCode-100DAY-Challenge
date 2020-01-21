#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> hashmap;
        int tmp = 0;
        int size = wall.size();

        if (size == 0) return 0;

        for (int i = 0; i < size; ++i) {
            tmp = 0;
            for (int j = 0; j < wall[i].size() - 1; ++j) { // do not count the last brick
                tmp += wall[i][j];
                if (!hashmap.count(tmp))
                    hashmap.insert(make_pair(tmp, 1));
                else
                    hashmap[tmp]++;
            }
        }

        if (hashmap.empty()) return size; // all layers have just one brick

        auto it_max = hashmap.begin();
        for (auto it = hashmap.begin(); it != hashmap.end(); ++it)
            if (it->second > it_max->second)
                it_max = it;
        
        return size - it_max->second;
    }
};

int main() {
    /**
     * You can add some test examples here.
     */
}