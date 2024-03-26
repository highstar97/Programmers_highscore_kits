#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int Tiredness, vector<vector<int>> Dungeons)
{
    int Answer = -1;
    sort(Dungeons.begin(), Dungeons.end());

    do
    {
        // Get MaxAnswer;
        int NumOfClear = 0;
        int CurrentTiredness = Tiredness;
        for (int i = 0; i < Dungeons.size(); ++i)
        {
            // 현재 피로도 >= 최소 필요 피로도
            if (CurrentTiredness >= Dungeons[i][0])
            {
                CurrentTiredness -= Dungeons[i][1];
                ++NumOfClear;
            }
            else
            {
                break;
            }
        }
        Answer = max(Answer, NumOfClear);
    } while (next_permutation(Dungeons.begin(), Dungeons.end()));

    return Answer;
}

int main()
{
    cout << solution(80, {{80, 20}, {50, 40}, {30, 10}}) << endl;
}