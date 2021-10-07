#include <iostream>
#include <vector>
#include <unordered_map>

int solution(std::vector<std::vector<std::string>> clothes)
{
    int answer = 1;
    std::unordered_map<std::string,int> UMap;
    for(auto data : clothes)
    {
        if(UMap.find(data[1]) == UMap.end())
            UMap[data[1]] = 1;
        else
            UMap[data[1]]++;
    }

    for(auto data : UMap)
        answer *= data.second + 1;
    
    return answer-1;
}

int main(){
    std::vector<std::vector<std::string>> clothes = {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};
    std::cout << solution(clothes);
}