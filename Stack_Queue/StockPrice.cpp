#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> Answer(prices.size(), 0);
    stack<int> Stack;

    for (int i = 0; i < prices.size(); ++i)
    {
        while (!Stack.empty() && prices[Stack.top()] > prices[i])
        {
            Answer[Stack.top()] = i - Stack.top();
            Stack.pop();
        }
        Stack.emplace(i);
    }
    while (!Stack.empty())
    {
        Answer[Stack.top()] = prices.size() - Stack.top() - 1;
        Stack.pop();
    }

    return Answer;
}

int main()
{
    vector<int> prices = {3, 5, 4, 2, 6, 7, 1, 2, 4};
    for (int data : solution(prices))
        cout << data << " ";
}