#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getNum(char ten, char one)
{
    return (ten - '0') * 10 + one - '0';
}

bool comp(string time1, string time2)
{
    int hour1 = getNum(time1[0], time1[1]);
    int hour2 = getNum(time2[0], time2[1]);
    if (hour1 != hour2) 
        return hour1 < hour2;
    int min1 = getNum(time1[3], time1[4]);
    int min2 = getNum(time2[3], time2[4]);
    return min1 < min2;
}

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) 
    {
        sort(timePoints.begin(), timePoints.end(), comp);
        int minDiff = 1440;
        int diff = 0;
        for (int i = 0; i < timePoints.size() - 1; ++i)
        {
            diff = difference(timePoints[i], timePoints[i + 1]);
            if (diff < minDiff)
                minDiff = diff;
        }
        diff = difference(timePoints[timePoints.size() - 1], timePoints[0]);
        if ( diff < minDiff)
            minDiff = diff;  
        return minDiff;
    }
private:
    int difference(string time1, string time2)
    {
        int hour1 = getNum(time1[0], time1[1]);
        int hour2 = getNum(time2[0], time2[1]);
        int min1 = getNum(time1[3], time1[4]);
        int min2 = getNum(time2[3], time2[4]);
        int diff = (hour2 - hour1) * 60 + min2 - min1;
        if (diff < 0) diff += 1440;
        return diff;
    }
};

int main()
{
    Solution s;
    vector<string> vec;
    vec.push_back("00:00");
    vec.push_back("23:59");
    vec.push_back("00:00");
    cout << s.findMinDifference(vec) << endl;
    return 0;
}