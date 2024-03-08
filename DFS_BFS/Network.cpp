#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int FindParent(int x, vector<int> &Parents)
{
    if (Parents[x] == x)
    {
        return x;
    }
    return Parents[x] = FindParent(Parents[x], Parents);
}

void Union(int x, int y, vector<int> &Parents)
{
    x = FindParent(x, Parents);
    y = FindParent(y, Parents);

    x < y ? Parents[y] = x : Parents[x] = y;
}

int solution(int n, vector<vector<int>> computers)
{
    set<int> Networks;
    vector<int> Parents(n);
    for (int i = 0; i < n; ++i)
    {
        Parents[i] = i;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (computers[i][j] == 1)
            {
                Union(i, j, Parents);
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        Networks.emplace(FindParent(i, Parents));
    }

    return Networks.size();
}

void DFS(int x, vector<bool> &IsVisited, const vector<vector<int>> &computers)
{
    IsVisited[x] = true;
    for (int i = 0; i < computers.size(); ++i)
    {
        if (IsVisited[i] == false && computers[x][i] == 1)
        {
            DFS(i, IsVisited, computers);
        }
    }
}

int solution2(int n, vector<vector<int>> computers)
{
    int answer = 0;
    vector<bool> IsVisited(n, false);

    for (int i = 0; i < n; ++i)
    {
        if (IsVisited[i] == false)
        {
            DFS(i, IsVisited, computers);
            ++answer;
        }
    }
    return answer;
}

int main()
{
    int n = 3;
    vector<vector<int>> computers = {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};
    cout << solution(n, computers) << " " << solution2(n, computers);
}