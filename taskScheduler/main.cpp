#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// with simulation, this solution is not fit for only returning an integer
class Solution1 {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> task_cnt(26, 0);
        vector<int> last_time(26, -1 * n - 1);
        vector<int> queue;
        for (int i = 0; i < tasks.size(); ++i)
            task_cnt[tasks[i] - 'A']++;
        // construct a priority queue, more tasks are priority-higher
        for (int i = 0; i < 26; ++i)
            queue.push_back(i);
        int tmp;
        for (int i = 0; i < 26; ++i) {
            for (int j = i + 1; j < 26; ++j)
                if (task_cnt[queue[i]] < task_cnt[queue[j]]) {
                    tmp = queue[i];
                    queue[i] = queue[j];
                    queue[j] = tmp;
                }
        }
        // simulation
        int time = 0;
        int que_idx, task_idx;
        while (task_cnt[queue[0]] > 0) {
            que_idx = 0;
            while (que_idx < 26) {
                if (task_cnt[queue[que_idx]] > 0 && time - last_time[queue[que_idx]] > n) {
                    break;
                }
                else if (task_cnt[queue[que_idx]] == 0) {
                    que_idx = 26;
                    break;
                }
                que_idx++;
            }
            
            if (que_idx == 26) {
                time++; // idle
                continue;
            }
            task_idx = queue[que_idx];
            task_cnt[task_idx]--;
            last_time[task_idx] = time;
            queue.erase(queue.begin() + que_idx);
            while (que_idx < 25 && task_cnt[queue[que_idx]] > task_cnt[task_idx])
                que_idx++;
            queue.insert(queue.begin() + que_idx, task_idx);
            time++;
        }
        return time;
    }
};

// arrange the most frequent tasks first, then arrange others
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> tasks_cnt(26, 0);
        for (int i = 0; i < tasks.size(); ++i)
            tasks_cnt[tasks[i] - 'A']++;
        sort(tasks_cnt.begin(), tasks_cnt.end());
        int max_task = tasks_cnt[25];
        int max_cnt = 1;
        while (max_cnt <= 25 && tasks_cnt[25 - max_cnt] == max_task)
            max_cnt++;
        int idles = (n - max_cnt + 1) * (max_task - 1);
        int leftTasks = tasks.size() - max_cnt * max_task;
        idles = max(0, idles - leftTasks);
        return tasks.size() + idles;
    }
};

int main() {
    Solution s;
    vector<char> tasks({'A','A','A','B','B','B'});
    cout << s.leastInterval(tasks, 2) << endl;
    return 0;
}