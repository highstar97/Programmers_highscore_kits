#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> solution(std::vector<int> array, std::vector<std::vector<int>> commands)
{
    std::vector<int> answer;
    for(auto data : commands)
    {
        std::vector<int> temp(array.begin()+data[0]-1,array.begin()+data[1]);
        sort(temp.begin(),temp.end());
        answer.emplace_back(temp[data[2]-1]);
    }
    return answer;
}

int main()
{
    std::vector<int> array = {1, 5, 2, 6, 3, 7, 4};
    std::vector<std::vector<int>> commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
    for(auto data : solution(array,commands))
        std::cout << data << " ";
}