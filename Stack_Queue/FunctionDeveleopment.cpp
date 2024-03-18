#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    int Day = 0;
    vector<int> Answer;
    queue<int> Queue;

    for (int i = 0; i < progresses.size(); ++i)
    {
        int rest = 100 - progresses[i];
        rest % speeds[i] > 0 ? Queue.emplace(rest / speeds[i] + 1) : Queue.emplace(rest / speeds[i]);
    }

    while (!Queue.empty())
    {
        int Count = 0;
        Day = Queue.front();
        while (!Queue.empty() && Queue.front() <= Day)
        {
            ++Count;
            Queue.pop();
        }
        Answer.emplace_back(Count);
    }

    return Answer;
}

int main()
{
    for (auto data : solution({0, 90, 99, 99, 80, 99}, {1, 1, 1, 1, 1, 1}))
        cout << data << " ";
}