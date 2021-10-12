#include <iostream>
#include <vector>
#include <queue>
#define ii std::pair<int,int>
auto cmp = [](ii& a, ii& b){
    if(a.first == b.first)
        return a.second > b.second;
    else return a.first > b.first;
    };

auto cmp2 = [](ii&a, ii& b){
    if(a.second == b.second)
        return a.first > b.first;
    else return a.second > b.second;
};

int solution(std::vector<std::vector<int>> jobs)
{
    int time;
    int answer = 0;
    std::priority_queue<ii,std::vector<ii>,decltype(cmp)> pq(cmp);
    for(auto data : jobs)
        pq.emplace(std::make_pair(data[0],data[1]));
    
    time = pq.top().first;
    std::priority_queue<ii,std::vector<ii>,decltype(cmp2)> stack_pq(cmp2);
    while (!pq.empty())
    {
        while (!pq.empty() && pq.top().first <= time)
        {
            stack_pq.emplace(pq.top());
            pq.pop();
        }
        if(stack_pq.empty())
            time = pq.top().first;
        else
        {
            answer += time + stack_pq.top().second - stack_pq.top().first;
            time = time + stack_pq.top().second;
            stack_pq.pop();
        }
    }
    while(!stack_pq.empty())
    {
        answer += time + stack_pq.top().second - stack_pq.top().first;
        time = time + stack_pq.top().second;
        stack_pq.pop();
    }
    return answer/jobs.size();
}

int main()
{
    std::vector<std::vector<int>> jobs = {{0,3},{3,8},{3,4},{6,1}};
    std::cout << solution(jobs);
}