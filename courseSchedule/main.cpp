#include <vector>
#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

/**HINT
 * In this file, I use two different strategies to finish the work: DFS and Kahn algorithm.
 * DFS is quite easy and brute, detecting whether there's a cycle
 * Kahn is another thought, trying to find nodes with indegree == 0, and delete these nodes, so and so forth.
 * 
 * Actually, when we face problems like 'Can we find a way to xxx ?' and 'Find the way to xxx.', the latter one
 * is usually more difficult, and more time complexed. However, in this Course Schedule problem, Kahn algorithm
 * can not only judge, but also give a topological sort for courses, while DFS can only do judgement. Besides, 
 * apparently, DFS is more complex than Kahn. 
 * From this point of view, DFS is totally beated by Kahn.
 */

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> adj(numCourses);
        vector<bool> visited(numCourses, false);
        unordered_set<int> courses;
        // construct the adj matrix
        for (int i = 0; i < prerequisites.size(); ++i)
            adj[prerequisites[i][1]].insert(prerequisites[i][0]);
        for (int i = 0; i < numCourses; ++i)
            if (!visited[i] && dfs(adj, courses, i, visited))
                return false;
        return true;
    }
private:
    bool dfs(const vector<unordered_set<int>> &adj, unordered_set<int> &courses, int course_id, vector<bool> &visited) {
        visited[course_id] = true;
        courses.insert(course_id);
        for (auto it = adj[course_id].begin(); it != adj[course_id].end(); ++it) {
            if (courses.count(*it) > 0 || dfs(adj, courses, *it, visited))
                return true;
        }
        courses.erase(course_id);
        return false;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i) {
            indegrees[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        return kahn(adj, indegrees, numCourses);
    }
private:
    bool kahn(const vector<vector<int>> &adj, vector<int> &indegrees, const int &num) {
        queue<int> courses;
        int cnt = 0;
        int course;
        for (int i = 0; i < num; ++i)
            if (indegrees[i] == 0) {
                courses.push(i);
                cnt++;
            }
        while (!courses.empty()) {
            course = courses.front();
            courses.pop();
            for (auto it = adj[course].begin(); it != adj[course].end(); ++it){
                indegrees[*it]--;
                if (indegrees[*it] == 0) {
                    courses.push(*it);
                    cnt++;
                }
            }
        }
        return cnt == num;
    }
};