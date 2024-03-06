#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    
    for(int i=0; i<commands.size(); ++i)
    {
        temp = array;
        sort(temp.begin()+commands[i][0] - 1, temp.begin()+commands[i][1]);
        answer.emplace_back(temp[commands[i][0] + commands[i][2] - 2]);
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