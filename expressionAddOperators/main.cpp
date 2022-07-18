#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Complexity: O(n * 4^n)
class Solution1 {

private:
    vector<string> ans;

    void checkAndWriteResultant(string expression, int target, int init_len)
    {
        int expression_len = expression.size();
        if (expression_len == 2 * init_len - 1)
        {
            int resultant = calculateExpression(expression, target);
            if (resultant == target)
            {
                ans.push_back(expression);
            }
        }
        else
        {
            checkAndWriteResultant(addOneOperator(expression, init_len, '+'), target, init_len);
            checkAndWriteResultant(addOneOperator(expression, init_len, '-'), target, init_len);
            checkAndWriteResultant(addOneOperator(expression, init_len, '*'), target, init_len);
        }
    }

    int getFirstMultiplyIdx(vector<char> & opers)
    {
        int idx = -1;
        for (int i = 0; i < opers.size(); ++i)
        {
            if (opers[i] == '*')
            {
                idx = i;
                break;
            }
        }

        return idx;
    }

    string addOneOperator(string expression, int init_len, char oper)
    {
        // Calculate the index to add operator
        int expression_len = expression.size();
        int target_index = 2 * (expression_len - init_len) + 1;

        // Insert the operator
        expression.insert(expression.begin() + target_index, oper);
        return expression;
    }

public:
    vector<string> addOperators(string num, int target) {
        ans = vector<string>();
        checkAndWriteResultant(num, target, num.size());

        return this->ans;
    }

    int calculateExpression(string expression, int expected_result=0)
    {
        if (expression.length() == 0)
            return 0;
        vector<int> nums;
        vector<char> opers;
        nums.push_back(expression[0] - '0');
        for (int i = 1; i < expression.size() - 1; i += 2)
        {
            opers.push_back(expression[i]);
            nums.push_back(expression[i + 1] - '0');
        }

        // Calculate first multily or divide
        int first_mul_or_div_idx = getFirstMultiplyIdx(opers);
        
        while (first_mul_or_div_idx >= 0)
        {
            char oper = opers[first_mul_or_div_idx];
            int num1 = nums[first_mul_or_div_idx];
            int num2 = nums[first_mul_or_div_idx + 1];

            // Here we only erase the second number because we will replace the first number later.
            nums.erase(nums.begin() + first_mul_or_div_idx + 1);
            opers.erase(opers.begin() + first_mul_or_div_idx);
            
            nums[first_mul_or_div_idx] = num1 * num2;
            first_mul_or_div_idx = getFirstMultiplyIdx(opers);
        }

        // Calculate plus and minus sequentially
        int resultant = nums[0];
        for (int i = 0; i < opers.size(); ++i)
        {
            if (opers[i] == '+')
                resultant += nums[i + 1];
            else
                resultant -= nums[i + 1];
        }

        return resultant;
    }
};

class Solution {
private:
    vector<string> ans;
    int target;

    void addOperatorsHelper(string expression, string num, long curr_result, long accumulative_multiplication)
    {
        if (num.size() == 0)
        {
            if (curr_result == this->target)
                ans.push_back(expression);
            return;
        }

        for (int selected_len = 1; selected_len <= num.size(); ++selected_len)
        {
            string curr_num = num.substr(0, selected_len);
            string left_num = num.substr(selected_len, num.length() - selected_len);

            if (expression.length() > 0)
            {
                addOperatorsHelper(expression + "+" + curr_num, left_num, curr_result + stoll(curr_num), stoll(curr_num));
                addOperatorsHelper(expression + "-" + curr_num, left_num, curr_result - stoll(curr_num), -stoll(curr_num));
                addOperatorsHelper(expression + "*" + curr_num, left_num, curr_result - accumulative_multiplication + stoll(curr_num) * accumulative_multiplication, stoll(curr_num) * accumulative_multiplication);
            }
            else
            {
                addOperatorsHelper(curr_num, left_num, stoll(curr_num), stoll(curr_num));
            }

            // Avoid the numer starting with 0
            if (selected_len == 1 && stoll(curr_num) == 0)
                break;
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        ans = vector<string>();
        this-> target = target;

        addOperatorsHelper("", num, 0, 0);

        return this->ans;
    }
};

void print(vector<string> ans)
{
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << endl;
    }
    cout << endl;
}

int main()
{
    Solution* s = new Solution();
    
    print(s->addOperators("232", 8));
    print(s->addOperators("123", 6));
    // cout << s->calculateExpression("2*3+2") << endl;
    print(s->addOperators("3456237490", 9191));
    print(s->addOperators("105", 5));
    print(s->addOperators("9999999999", 9191));

    return 0;
}
