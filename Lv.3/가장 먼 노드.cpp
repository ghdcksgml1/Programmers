#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> a[20001];
bool visit[20001];
int Max_dist = -1;
int Max_cnt = 0;

void reclusion()
{
    queue<pair<int, int> > q; // pair<노드,간선의깊이>
    q.push({1, 0});           // 노드 1을 넣어준다.
    visit[1] = true;          // 노드 1 방문 표시

    while (!q.empty())
    { // queue가 비어있을 때 까지 반복
        auto cur = q.front();
        q.pop(); // q의 front를 뺀뒤 pop

        // 간선의 깊이가 같으면 cnt++
        if (Max_dist == cur.second)
            Max_cnt++;
        // 간선의 깊이가 더 크면, 간선의 깊이를 최신화시킨다.
        else if (Max_dist < cur.second)
        {
            Max_dist = cur.second;
            Max_cnt = 1;
        }

        // cur.first 노드의 방문하지 않은 모든 노드를 방문해준다.
        for (int i = 0; i < a[cur.first].size(); i++)
        {
            int y = a[cur.first][i];
            if (!visit[y])
            {
                visit[y] = true;
                q.push({y, cur.second + 1});
            }
        }
    }
}

int solution(int n, vector<vector<int> > edge)
{
    int answer = 0;
    for (int i = 0; i < edge.size(); i++)
    {
        int fir = edge[i][0];
        int sec = edge[i][1];
        a[fir].push_back(sec);
        a[sec].push_back(fir);
    }
    reclusion();
    answer = Max_cnt;
    return answer;
}