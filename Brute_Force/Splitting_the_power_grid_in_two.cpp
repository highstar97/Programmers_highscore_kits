#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 101

using namespace std;

void BFS(int Start, int End, int &Count, vector<int> *Graphs)
{
    queue<int> Queue;
    vector<bool> IsVisited(MAX, false);

    Queue.emplace(Start);
    IsVisited[Start] = true;
    IsVisited[End] = true;

    while (!Queue.empty())
    {
        int Current = Queue.front();
        Queue.pop();

        for (int i = 0; i < Graphs[Current].size(); ++i)
        {
            int Next = Graphs[Current][i];

            if (IsVisited[Next])
            {
                continue;
            }
            ++Count;
            Queue.push(Next);
            IsVisited[Next] = true;
        }
    }
}

int solution(int N, vector<vector<int>> Wires)
{
    int Answer = MAX;
    vector<int> Graphs[MAX];

    for (auto Wire : Wires)
    {
        Graphs[Wire[0]].emplace_back(Wire[1]);
        Graphs[Wire[1]].emplace_back(Wire[0]);
    }

    for (auto Wire : Wires)
    {
        int Count = 1;
        int Start = Wire[0];
        int End = Wire[1];

        BFS(Start, End, Count, Graphs);
        Answer = min(Answer, abs(Count - (N - Count)));
    }

    return Answer;
}

int main()
{
    cout << solution(4, {{1, 2}, {2, 3}, {3, 4}}) << endl;
}