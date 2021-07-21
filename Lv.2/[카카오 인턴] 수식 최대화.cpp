#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> arr;
vector<char> arr2;

vector<long long> cpy_arr;
vector<char> cpy_arr2;

long long func(int mul,int plus,int minus){
    cpy_arr = arr;
    cpy_arr2 = arr2;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < cpy_arr2.size(); j++)
        {
            if (i == mul && cpy_arr2[j] == '*')
            {
                cpy_arr[j] = cpy_arr[j] * cpy_arr[j + 1];
                cpy_arr.erase(cpy_arr.begin() + j + 1);
                cpy_arr2.erase(cpy_arr2.begin() + j);
                j--;
            }
            if (i == plus && cpy_arr2[j] == '+')
            {
                cpy_arr[j] = cpy_arr[j] + cpy_arr[j + 1];
                cpy_arr.erase(cpy_arr.begin() + j + 1);
                cpy_arr2.erase(cpy_arr2.begin() + j);
                j--;
            }
            if (i == minus && cpy_arr2[j] == '-')
            {
                cpy_arr[j] = cpy_arr[j] - cpy_arr[j + 1];
                cpy_arr.erase(cpy_arr.begin() + j + 1);
                cpy_arr2.erase(cpy_arr2.begin() + j);
                j--;
            }
        }
    }
    return abs(cpy_arr[0]);
}

long long solution(string expression)
{
    int idx = 0;
    for (int i = 0; i <= expression.size(); i++)
    {
        if (expression[i] == '*' || expression[i] == '+' || expression[i] == '-' || i == expression.size())
        {
            if (i != expression.size())
            {
                arr2.push_back(expression[i]);
            }
            if (idx == 3)
            {
                int result = (expression[i - 3] - '0') * 100 + (expression[i - 2] - '0') * 10 + (expression[i - 1] - '0');
                arr.push_back(result);
                idx = 0;
            }
            if (idx == 2)
            {
                int result = (expression[i - 2] - '0') * 10 + (expression[i - 1] - '0');
                arr.push_back(result);
                idx = 0;
            }
            if (idx == 1)
            {
                arr.push_back(expression[i - 1] - '0');
                idx = 0;
            }
        }
        else
        {
            idx++;
        }
    }

    long long answer = 0;
    long long Max = 0;

    // * + -
    if (Max < func(0,1,2)) 
        Max = cpy_arr[0];
    // * - +
    if (Max < func(0, 2, 1))
        Max = cpy_arr[0];
    // + * -
    if (Max < func(1, 0, 2))
        Max = cpy_arr[0];
    // + - *
    if (Max < func(2, 0, 1))
        Max = cpy_arr[0];
    // - * +
    if (Max < func(1, 2, 0))
        Max = cpy_arr[0];
    // - + *
    if (Max < func(2, 1, 0))
        Max = cpy_arr[0];
    
    //////////

    return Max;
}