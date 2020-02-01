#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i) {
            indegrees[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        return Kahn(numCourses, adj, indegrees);
    }
private:
    vector<int> Kahn(int numCourses, const vector<vector<int>> &adj, vector<int> &indegrees) {
        queue<int> courses;
        vector<int> ans;
        int course_id;
        for (int i = 0; i < numCourses; ++i)
            if (indegrees[i] == 0)
                courses.push(i);
        
        while (!courses.empty()) {
            course_id = courses.front();
            courses.pop();
            ans.push_back(course_id);
            for (int i = 0; i < adj[course_id].size(); ++i)
                if (--indegrees[adj[course_id][i]] == 0)
                    courses.push(adj[course_id][i]);
        }

        if (ans.size() < numCourses) {
            ans.clear();
            return ans;
        }
        return ans;
    }
};