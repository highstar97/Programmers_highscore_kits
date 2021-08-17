#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

int solution(std::vector<std::vector<std::string>> clothes) {
    int answer = 1;
    std::unordered_map<std::string, int> u_map;
    for(auto data : clothes){
        if(u_map.find(data[1]) == u_map.end())
            u_map[data[1]] = 1;
        else
            u_map[data[1]]++;
    }
    for(auto data : u_map){
        answer *= (data.second + 1);
    }

    return answer - 1;
}

int main(){
    std::vector<std::vector<std::string>> clothes = {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};
    std::cout << solution(clothes);
}