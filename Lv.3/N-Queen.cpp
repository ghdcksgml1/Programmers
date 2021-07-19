#include <string>
#include <vector>

using namespace std;

int sum = 0;

// bool queen_1[20]; // 행
bool queen_2[20]; // 열
bool queen_3[50]; // 아래 대각선
bool queen_4[50]; // 위 대각선
// 2:3 3:5 4:7 5:9
void backtracking(int x, int n)
{
    if (x == n)
    {
        sum++;
        return;
    }
    for (int y = 0; y < n; y++)
    {
        // queen_3: y-x+n
        // queen_4: x+y
        if (!queen_2[y] && !queen_3[y - x + n] && !queen_4[x + y])
        {
            queen_2[y] = true;
            queen_3[y - x + n] = true;
            queen_4[x + y] = true;
            backtracking(x + 1, n);
            queen_2[y] = false;
            queen_3[y - x + n] = false;
            queen_4[x + y] = false;
        }
    }
}

int solution(int n)
{
    int answer = 0;
    backtracking(0, n);
    answer = sum;
    return answer;
}