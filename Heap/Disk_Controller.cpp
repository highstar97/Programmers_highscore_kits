#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct CompareByStartTime
{
    bool operator()(const vector<int> &f, const vector<int> &b)
    {
        if (f[0] == b[0])
        {
            return f[1] > b[1];
        }
        return f[0] > b[0];
    }
};

struct CompareByActingTime
{
    bool operator()(const vector<int> &f, const vector<int> &b)
    {
        return f[1] > b[1];
    }
};
int solution(vector<vector<int>> jobs)
{
    int Answer = 0;
    int CurrentTime = 0;
    priority_queue<vector<int>, vector<vector<int>>, CompareByStartTime> HeapByStartTime(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, CompareByActingTime> HeapByActingTime;

    while (!HeapByStartTime.empty())
    {
        // 현재 시간까지 할 수 있는 모든 작업을 HeapByActingTime에 추가한다.
        while (!HeapByStartTime.empty() && HeapByStartTime.top()[0] <= CurrentTime)
        {
            HeapByActingTime.emplace(HeapByStartTime.top());
            HeapByStartTime.pop();
        }
        // 현재시간까지 수행할 수 있는 작업이 없다면 가장 빠른 작업을 대기열에 추가한다.
        if (HeapByActingTime.empty())
        {
            CurrentTime = HeapByStartTime.top()[0];
        }
        // 현재 시간에 수행할 수 있는 작업들 중, 소요시간이 가장 작은 작업부터 실행
        else
        {
            CurrentTime += HeapByActingTime.top()[1];
            Answer += CurrentTime - HeapByActingTime.top()[0];
            HeapByActingTime.pop();
        }
    }
    // HeapByActingTime을 모두 비웠을 때, 모든 작업 수행 완료된 것
    while (!HeapByActingTime.empty())
    {
        CurrentTime += HeapByActingTime.top()[1];
        Answer += CurrentTime - HeapByActingTime.top()[0];
        HeapByActingTime.pop();
    }
    return Answer / jobs.size();
}

int main()
{
    vector<vector<int>> jobs = {{0, 3}, {3, 8}, {3, 4}, {6, 1}};
    cout << solution(jobs);
}