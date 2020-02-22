#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;  
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxHeap.empty() && minHeap.empty())
            maxHeap.push(num);
        else if (maxHeap.size() > minHeap.size()) { // should goto minHeap
            if (num >= maxHeap.top())
                minHeap.push(num);
            else {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            }
        }
        else if (maxHeap.size() < minHeap.size()) { // should goto maxHeap
            if (num <= minHeap.top())
                maxHeap.push(num);
            else {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            }
        }
        else {
            if (num >= minHeap.top())
                minHeap.push(num);
            else
                maxHeap.push(num);
        }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size())
            return (maxHeap.top() + minHeap.top()) / 2.0;
        else
            return (maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top()) / 1.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
    MedianFinder *obj = new MedianFinder();
    obj->addNum(2);
    cout << obj->findMedian() << endl;
    obj->addNum(3);
    cout << obj->findMedian() << endl;
    return 0;
}