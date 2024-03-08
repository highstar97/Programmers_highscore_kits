#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n, m;
int drow[4] = {-1, 1, 0, 0};
int dcol[4] = {0, 0, -1, 1};

int solution(vector<vector<int>> maps)
{
    n = maps.size();
    m = maps[0].size();
    int answer = INT_MAX;
    vector<vector<bool>> IsVisited(n, vector<bool>(m, false));
    queue<pair<pair<int, int>, int>> Queue; // {{row,col},cost}

    // BFS
    Queue.emplace(make_pair(make_pair(0, 0), 1));
    IsVisited[0][0] = true;
    while (!Queue.empty())
    {
        int row = Queue.front().first.first;
        int col = Queue.front().first.second;
        int cost = Queue.front().second;
        Queue.pop();

        if (row == n - 1 && col == m - 1)
        {
            answer = min(answer, cost);
        }

        for (int i = 0; i < 4; ++i)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m)
            {
                continue;
            }

            if (maps[nrow][ncol] == 0 || IsVisited[nrow][ncol] == true)
            {
                continue;
            }

            IsVisited[nrow][ncol] = true;
            Queue.emplace(make_pair(make_pair(nrow, ncol), cost + 1));
        }
    }

    if (answer == INT_MAX)
    {
        answer = -1;
    }
    return answer;
}

int main()
{
    vector<vector<int>> maps = {{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}};
    cout << solution(maps);
}