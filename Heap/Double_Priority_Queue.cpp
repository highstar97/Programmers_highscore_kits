#include <iostream>
#include <set>
#include <vector>

std::vector<int> solution(std::vector<std::string> operations)
{
    std::vector<int> answer;
    std::multiset<int> s;
    for(auto data : operations) {
        if(data[0] == 'I') s.emplace(stoi(data.substr(2))); 
        else if(data[2] == '1' && !s.empty()) { s.erase(--s.end()); }
        else if(!s.empty()) { s.erase(s.begin()); }
    }
    if(s.empty()) { return {0,0}; }
    answer.emplace_back(*(--s.end())); 
    answer.emplace_back(*s.begin());
    return answer;
}

int main(){
    std::vector<std::string> operations = {"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"};
    for(int data : solution(operations))
        std::cout << data << ' ';
}