#include <iostream>
#include <vector>
using namespace std;


class RecentCounter {
private:
    vector<int> calls;
    int search(int lowBound) {
        if (lowBound <= 0) {
            return 0;
        }
        int start = 0, end = calls.size();
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (calls[mid] < lowBound) {
                start = mid + 1;
            }
            else if (calls[mid] > lowBound) {
                end = mid;
            }
            else {
                return mid;
            }
        }
        return start;
    }
public:
    RecentCounter() {
        calls.clear();
    }
    
    int ping(int t) {
        int lowBound = t - 3000;
        if (calls.empty()) {
            calls.push_back(t);
            return 1;
        }
        int startIdx = search(lowBound);
        calls.erase(calls.begin(), calls.begin() + startIdx);
        calls.push_back(t);
        return calls.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main() {
    RecentCounter* obj = new RecentCounter();
    cout << obj->ping(1) << endl;
    cout << obj->ping(3000) << endl;
    cout << obj->ping(3001) << endl;
    cout << obj->ping(3002) << endl;
    cout << obj->ping(6001) << endl;
}