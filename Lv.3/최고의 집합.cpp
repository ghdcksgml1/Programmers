#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s)
{
    vector<int> answer;
    if (s >= n)
    {
        int q = s / n;
        int r = s % n;
        for (int i = 0; i < n; i++)
        {
            if (i < n - r)
            {
                answer.push_back(q);
            }
            else
            {
                answer.push_back(q + 1);
            }
        }
    }
    else
    {
        answer.push_back(-1);
    }
    return answer;
}