#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define si std::pair<std::string, int>

std::vector<int> solution(std::vector<std::string> genres, std::vector<int> plays)
{
    std::vector<int> answer;
    std::unordered_map<std::string, int> Genre_TotalPlays;
    std::unordered_map<std::string, std::vector<int>> Genre_Plays;
    for(int i=0; i<genres.size(); i++)
    {
        if(Genre_TotalPlays.find(genres[i]) == Genre_TotalPlays.end())
            Genre_TotalPlays[genres[i]] = plays[i];
        else
            Genre_TotalPlays[genres[i]] += plays[i];
        Genre_Plays[genres[i]].emplace_back(plays[i]);
    }
    
    std::vector<si> v1(Genre_TotalPlays.begin(), Genre_TotalPlays.end());
    sort(v1.begin(),v1.end(),[](si& a, si& b){
        return a.second > b.second;
    });

    for(auto& data : Genre_Plays)
    {
        sort(data.second.begin(), data.second.end(), [](int &a, int &b)->bool{
            return a > b;
        });
    }

    for(auto data : v1){
        int count = 0;
        int max = (Genre_Plays[data.first].size() >= 2) ? 2 : 1;
        do{
            for(int i=0; i<genres.size(); i++){
                if(genres[i] == data.first && plays[i] == Genre_Plays[data.first][count]){
                    answer.emplace_back(i);
                    plays[i] = 0;
                }
            }
            count++;
        }while(count < max);
    }

    return answer;
}

int main(){
    std::vector<std::string> genres = {"classic", "pop", "classic", "classic","jazz","pop", "Rock", "jazz"};
    std::vector<int> plays = {150, 600, 150, 800, 1100, 2500, 1000, 1000};
    for(auto data : solution(genres,plays))
        std::cout << data << " ";
}