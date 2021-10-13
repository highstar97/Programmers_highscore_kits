#include <iostream>
#include <vector>
#include <algorithm>

std::string solution(std::vector<int> numbers)
{
    std::string answer;
    std::vector<std::string> v;
    for(auto data : numbers)
        v.emplace_back(std::to_string(data));
    sort(v.begin(),v.end(),[](std::string a ,std::string b){
        for(int i=0; i<4; i++)
        {
            a += a; b += b;
        }
        a = a.substr(0,4);  b = b.substr(0,4);
        return a > b;
    });
    std::string iszero;
    for(auto data : v)
    {
        answer += data;
        iszero += "0";
    }
    if(answer == iszero)    return "0";
    else    return answer;
}

int main()
{
    std::vector<int> numbers = {0,0,0,0};
    std::cout << solution(numbers);
}