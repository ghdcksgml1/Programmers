#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int> > queries)
{
    vector<int> answer;
    int arr[102][102];
    int num = 1;
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            arr[i][j] = num;
            num++;
        }
    }
    // (queries[0],queries[1]) => (queries[0],queries[3])
    // (queries[0],queries[3]) => (queries[2],queries[3])
    // (queries[2],queries[3]) => (queries[2],queries[1])
    // (queries[2],queries[1]) => (queries[0],queries[1])
    for (int q = 0; q < queries.size(); q++)
    {
        int Min = arr[queries[q][0]][queries[q][1]];
        int temp = arr[queries[q][0]][queries[q][1]];
        cout << q << ' ';
        for (int i = queries[q][0]; i < queries[q][2]; i++)
        {
            arr[i][queries[q][1]] = arr[i + 1][queries[q][1]];
            Min = min(Min, arr[i][queries[q][1]]);
        }
        for (int i = queries[q][1]; i < queries[q][3]; i++)
        {
            arr[queries[q][2]][i] = arr[queries[q][2]][i + 1];
            Min = min(Min, arr[queries[q][2]][i]);
        }
        for (int i = queries[q][2]; i > queries[q][0]; i--)
        {
            arr[i][queries[q][3]] = arr[i - 1][queries[q][3]];
            Min = min(Min, arr[i][queries[q][3]]);
        }

        for (int i = queries[q][3]; i > queries[q][1] + 1; i--)
        {
            arr[queries[q][0]][i] = arr[queries[q][0]][i - 1];
            Min = min(Min, arr[queries[q][0]][i]);
        }
        arr[queries[q][0]][queries[q][1] + 1] = temp;
        answer.push_back(Min);
    }
    return answer;
}