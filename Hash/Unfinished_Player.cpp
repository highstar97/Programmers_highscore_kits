#include <iostream>
#include <vector>
#include <set>

std::string solution(std::vector<std::string> participant, std::vector<std::string> completion) {
    std::multiset<std::string> MultiSet;
    for(auto data : participant)
        MultiSet.emplace(data);
    for(auto data : completion)
        MultiSet.erase(MultiSet.find(data));
    return *MultiSet.begin();
}

int main(){
    std::vector<std::string> participant = {"mislav", "stanko", "mislav", "ana"};
    std::vector<std::string> completion = {"stanko", "ana", "mislav"};
    std::cout << solution(participant,completion);
}