#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> Answer;
    stack<int> Stack;

    for (int i = 0; i < arr.size(); ++i)
    {
        if (i == 0)
        {
            Stack.emplace(arr[i]);
            Answer.emplace_back(arr[i]);
        }

        if (Stack.top() != arr[i])
        {
            Stack.emplace(arr[i]);
            Answer.emplace_back(arr[i]);
        }
    }
    return Answer;
}

vector<int> solution2(vector<int> arr)
{
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    return arr;
}

int main()
{
    vector<int> arr = {4, 4, 4, 4, 3, 3, 4};
    for (int data : solution(arr))
    {
        cout << data << " ";
    }
}