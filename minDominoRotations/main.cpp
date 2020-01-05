#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B)
    {
        int ansA = -1, ansB = -1;
        int tmpA = 0, tmpB = 0;
        bool flag = true; // judge if the loop is broken
        // rotate to all A[0] value
        int target = A[0];
        for (int i = 0; i < A.size(); ++i)
        {
            if (A[i] != target && B[i] != target)
            {
                flag = false;
                break;
            }
            if (A[i] != target)
                tmpA++;
            if (B[i] != target)
                tmpB++;
        }
        if (flag)
            ansA = tmpA < tmpB ? tmpA : tmpB;
        // rotate to all B[0] value
        flag = true;
        target = B[0];
        tmpA = tmpB = 0;
        for (int i = 0; i < A.size(); ++i)
        {
            if (A[i] != target && B[i] != target)
            {
                flag = false;
                break;
            }
            if (A[i] != target)
                tmpA++;
            if (B[i] != target)
                tmpB++;
        }
        if (flag)
            ansB = tmpA < tmpB ? tmpA : tmpB;
        // parse final answer
        if (ansA < 0 && ansB < 0)
            return -1;
        if (ansA < 0)
            return ansB;
        if (ansB < 0)
            return ansA;
        else
            return ansA < ansB ? ansA : ansB;
    }
};

int main()
{
    
}