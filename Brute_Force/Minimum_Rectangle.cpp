#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int MaxOfMax = 0, MaxOfMin = 0;
    for (int i = 0; i < sizes.size(); ++i)
    {
        MaxOfMax = max(MaxOfMax, max(sizes[i][0], sizes[i][1]));
        MaxOfMin = max(MaxOfMin, min(sizes[i][0], sizes[i][1]));
    }
    return MaxOfMax * MaxOfMin;
}

int main()
{
    cout << solution({{60, 50}, {30, 70}, {60, 30}, {80, 40}});
}