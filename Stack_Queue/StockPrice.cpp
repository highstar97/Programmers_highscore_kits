#include <iostream>
#include <vector>
#include <stack>

std::vector<int> solution(std::vector<int> prices)
{
    int size = prices.size();
    std::vector<int> answer(prices.size());
    std::stack<int> s;
    for(int i=0; i<size; i++)
    {
        while(!s.empty() && prices[s.top()] > prices[i])
        {
            answer[s.top()] = i-s.top();
            s.pop();
        }
        s.emplace(i);
    }
    while(!s.empty())
    {
        answer[s.top()] = size - s.top() - 1;
        s.pop();
    }
    return answer;
}

int main()
{
    std::vector<int> prices = {3,5,4,2,6,7,1,2,4};
    for(int data : solution(prices))
        std::cout << data << " ";
}