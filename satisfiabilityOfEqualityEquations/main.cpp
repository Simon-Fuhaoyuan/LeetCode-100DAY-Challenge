#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        // equality
        vector<unordered_set<char>> equal_groups;
        char target1, target2;
        int group_id1, group_id2;
        for (int i = 0; i < equations.size(); ++i) {
            if (equations[i][1] == '!')
                continue;
            target1 = equations[i][0];
            target2 = equations[i][3];
            group_id1 = check_group_id(equal_groups, target1);
            group_id2 = check_group_id(equal_groups, target2);
            if (group_id1 == group_id2 && group_id1 == -1) {
                unordered_set<char> group;
                group.insert(target1);
                group.insert(target2);
                equal_groups.push_back(group);
            }
            else if (group_id1 == -1) {
                equal_groups[group_id2].insert(target1);
            }
            else if (group_id2 == -1) {
                equal_groups[group_id1].insert(target2);
            }
            else if (group_id1 != group_id2) {
                equal_groups[group_id1].insert(equal_groups[group_id2].begin(), equal_groups[group_id2].end());
                equal_groups.erase(equal_groups.begin() + group_id2);
            }
        }

        // inequality
        for (int i = 0; i < equations.size(); ++i) {
            if (equations[i][1] == '=')
                continue;
            target1 = equations[i][0];
            target2 = equations[i][3];
            if (target1 == target2)
                return false;
            group_id1 = check_group_id(equal_groups, target1);
            group_id2 = check_group_id(equal_groups, target2);
            if (group_id1 == group_id2 && group_id1 != -1 ) {
                return false;
            }
        }

        return true;
    }

private:
    int check_group_id(vector<unordered_set<char>>& equal_groups, char target) {
        int group_id = -1;
        for (int i = 0; i < equal_groups.size(); ++i) {
            if (equal_groups[i].count(target))
                return i;
        }

        return group_id;
    }
};