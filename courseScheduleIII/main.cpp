#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// brute force
// Not much to explain
class Solution1 {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int num = courses.size();
        vector<bool> visited(num, false);
        int day = 0;

        return scheduleCourse(courses, visited, day, num);
    }
private:
    int scheduleCourse(vector<vector<int>> &courses, vector<bool> &visited, int day, int num) {
        int max_course = 0;
        int tmp;
        for (int i = 0; i < num; ++i)
            if (day + courses[i][0] <= courses[i][1] && !visited[i]) {
                visited[i] = true;
                tmp = 1 + scheduleCourse(courses, visited, day + courses[i][0], num);
                if (tmp > max_course)
                    max_course = tmp;
                visited[i] = false;
            }
        
        return max_course;
    }
};

// Greedy algorithm
// First sort the courses by the deadline, we need to first finish earlier deadline.
// Then, use a priority queue (maximum heap) to store each course time.
// Each time adding a new course, if current_time + course[0] > course[1], we need
// to delete the current longest course, which is the reason why we use priority queue.
class Solution2 {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), comp);
        priority_queue<int> heap;
        int time = 0;
        for (auto it = courses.begin(); it != courses.end(); ++it) {
            heap.push((*it)[0]);
            time += (*it)[0];
            if (time > (*it)[1]) {
                time -= heap.top();
                heap.pop();
            }
        }

        return heap.size();
    }
private:
    bool comp(vector<int> a, vector<int> b) {
        return a[1] < b[1];
    }
};

int main() {

}