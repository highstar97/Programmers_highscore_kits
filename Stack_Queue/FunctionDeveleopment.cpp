#include <iostream>
#include <string>
#include <vector>
#include <math.h>

std::vector<int> solution(std::vector<int> progresses, std::vector<int> speeds) {
    int count = 1;
    std::vector<int> answer;
    std::vector<int> during_time(progresses.size(),0);
    for(int i=0; i<during_time.size(); i++)
    {
        during_time[i] = ceil((static_cast<double>(100 - progresses[i]))/speeds[i]);
    }

    for(int i=1; i<during_time.size(); i++)
    {
        if(during_time[i-1] < during_time[i])
        {
            answer.emplace_back(count);
            count = 1;
        }
        else
        {
            during_time[i] = during_time[i-1];
            count++;
        }
    }
    answer.emplace_back(count);
    return answer;
}

int main()
{
    for(auto data : solution({0, 90, 99, 99, 80, 99},{1, 1, 1, 1, 1, 1}))
        std::cout << data << " ";
}