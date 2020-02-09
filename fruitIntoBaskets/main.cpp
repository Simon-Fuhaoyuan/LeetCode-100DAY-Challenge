#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int type1 = tree[0], type2 = -1; // -1 means no ensured type
        int now_type = -1;
        int index = 0;
        int max_num = 0, tmp_num = 0, now_type_num = 0;
        int size = tree.size();
        while (index < size) {
            if (tree[index] == now_type) { // type continues
                tmp_num++;
                now_type_num++;
                index++;
            }
            else if (tree[index] == type1 || tree[index] == type2) { // transist a type
                tmp_num++;
                now_type = tree[index];
                now_type_num = 1;
                index++;
            }
            else if (type2 == -1) { // no type matched, but we have an empty basket
                type2 = tree[index];
            }
            else { // a new type occurs
                if (tmp_num > max_num)
                    max_num = tmp_num;
                type1 = now_type;
                type2 = -1;
                tmp_num = now_type_num;
            }
        }
        if (tmp_num > max_num)
            max_num = tmp_num;
        return max_num;
    }
};

int main() {
    Solution s;
    vector<int> trees({3,3,3,1,2,1,1,2,3,3,4});
    cout << s.totalFruit(trees) << endl;
    return 0;
}