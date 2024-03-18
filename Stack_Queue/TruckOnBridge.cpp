#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int Time = 0, Index = 0, WeightOnBridge = 0;
    queue<pair<int, int>> OnBridge; // {Weight, Time}

    while (Index < truck_weights.size())
    {
        if (WeightOnBridge + truck_weights[Index] <= weight)
        {
            OnBridge.emplace(make_pair(truck_weights[Index], Time));
            WeightOnBridge += truck_weights[Index++];
            ++Time;
        }
        else
        {
            Time = max(Time, OnBridge.front().second + bridge_length);  // ***
            WeightOnBridge -= OnBridge.front().first;
            OnBridge.pop();
        }
    }

    while (!OnBridge.empty())
    {
        Time = OnBridge.front().second + bridge_length;
        OnBridge.pop();
    }
    return ++Time;
}

int main()
{
    int bridge_length = 2;
    int weight = 10;
    vector<int> truck_weights = {7, 4, 5, 6};
    cout << solution(bridge_length, weight, truck_weights) << endl;
    cout << solution(100, 100, {10, 10, 10, 10, 10, 10, 10, 10, 10, 10}) << endl;
    cout << solution(5, 5, {2, 2, 2, 2, 1, 1, 1, 1, 1}) << endl;
}