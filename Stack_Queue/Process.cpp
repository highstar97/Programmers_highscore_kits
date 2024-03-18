#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int Answer = 1;
    priority_queue<int, vector<int>, less<int>> PriorityQueue(priorities.begin(), priorities.end());
    queue<pair<int, int>> PriorityIndexQueue;

    for (int i = 0; i < priorities.size(); ++i)
    {
        PriorityIndexQueue.emplace(make_pair(priorities[i], i));
    }

    while (!PriorityQueue.empty())
    {
        while (PriorityIndexQueue.front().first != PriorityQueue.top())
        {
            PriorityIndexQueue.emplace(PriorityIndexQueue.front());
            PriorityIndexQueue.pop();
        }

        if (PriorityIndexQueue.front().second == location)
        {
            return Answer;
        }

        PriorityQueue.pop();
        PriorityIndexQueue.pop();
        ++Answer;
    }

    return Answer;
}

int main()
{
    cout << solution({2, 1, 3, 2}, 2);
}