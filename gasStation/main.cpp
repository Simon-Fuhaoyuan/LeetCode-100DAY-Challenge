#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        int min_gas = INT_MAX, min_index = 0;
        int gas_total = 0;
        for (int i = 0; i < size; ++i) {
            gas_total = gas_total + gas[i] - cost[i];
            if (gas_total < min_gas) {
                min_gas = gas_total;
                min_index = i;
            }
        }
        if (gas_total < 0)
            return -1;
        else
            return (++min_index) % size;
    }
};

int main() {
    Solution s;
    vector<int> gas({1,2,3,4,5});
    vector<int> cost({3,4,5,1,2});
    cout << s.canCompleteCircuit(gas, cost) << endl;

    return 0;
}