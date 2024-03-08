#include <iostream>
#include <string>
#include <vector>

using namespace std;

void DFS(int depths, int sum, const int target, int &answer, vector<int> &numbers)
{
    if(depths == numbers.size())
    {
        if(sum == target)
        {
            ++answer;
        }
        return;
    }

    DFS(depths+1, sum+numbers[depths], target, answer, numbers);
    DFS(depths+1, sum-numbers[depths], target, answer, numbers);
}

int solution(vector<int> numbers, int target)
{
    int answer = 0;
    DFS(0, 0,target, answer, numbers);
    return answer;
}

int main()
{
    int target = 3;
    vector<int> numbers = {1, 1, 1, 1, 1};
    cout << solution(numbers, target);
}