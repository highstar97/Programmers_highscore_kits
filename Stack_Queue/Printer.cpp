#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define ii std::pair<int,int>

int solution(std::vector<int> priorities, int location)
{
    int answer = 1;
    std::queue<ii> q;
    for(int i=0; i<priorities.size(); i++)
    {
        q.emplace(std::make_pair(priorities[i],i));
    }
    sort(priorities.begin(),priorities.end(),[](int& a, int& b){ return a > b; });
    while(!q.empty())
    {
        if(*priorities.begin() == q.front().first)
        {       
            if(q.front().second == location)
                return answer;
            priorities.erase(priorities.begin());
            q.pop();
            answer++;
        }
        else
        {
            q.emplace(q.front());
            q.pop();
        }
    }
    return -1;
}

int main()
{
    std::vector<int> priorities = {1, 1, 9, 1, 1, 1};
    int location = 0;
    std::cout << solution(priorities,location);
}