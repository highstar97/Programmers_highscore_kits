#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

std::string solution(std::vector<std::string> participant, std::vector<std::string> completion) {
    std::string answer = "";
    std::unordered_map<std::string,int> player;
    for(auto data : participant){
        player[data]++;
    }
    for(auto data : completion){
        player[data]--;
    }
    for(auto data : player){
        if(data.second == 1){
            answer = data.first;
            return answer;
        }
    }
    return answer;
}

int main(){
    std::vector<std::string> participant = {"mislav", "stanko", "mislav", "ana"};
    std::vector<std::string> completion = {"stanko", "ana", "mislav"};
    std::cout << solution(participant,completion);
}