#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string,vector<int>> map_genres_index;
    unordered_map<string,int> map_genres_plays;

    for(int i=0; i<genres.size(); i++){
        map_genres_index[genres[i]].emplace_back(i);
        map_genres_plays[genres[i]] += plays[i];
    }

    // 많이 재생된 순으로 genres_list에 넣음
    vector<string> genres_list;
    for(auto it=map_genres_plays.begin(); it != map_genres_plays.end(); it++){
        auto max_index = it;
        for(auto it2=map_genres_plays.begin(); it2 !=map_genres_plays.end(); it2++){
            if(max_index->second < it2->second){
                max_index = it2;
            }
        }
        max_index->second = 0;
        genres_list.emplace_back(max_index->first);
    }

    // 많이 재생된 장르 순으로 출력
    for(int i=0; i<genres_list.size(); i++){
        pair<int,int> index_play1 = make_pair(0,0);
        pair<int,int> index_play2 = make_pair(0,0);
        // 가장 많이 재생된 앨범 번호와 재생횟수를 pair로 저장
        for(auto data : map_genres_index[genres_list[i]]){
            if(plays[data] > index_play1.second){
                index_play2.first = index_play1.first;
                index_play2.second = index_play1.second;
                index_play1.first = data;
                index_play1.second = plays[data];
            }
            else if(plays[data] > index_play2.second){
                index_play2.first = data;
                index_play2.second = plays[data];
            }
        }

        answer.emplace_back(index_play1.first);
        if(index_play2.second != 0)
            answer.emplace_back(index_play2.first);
    }
    
    return answer;
}

int main(){
    std::vector<std::string> genres = {"classic", "pop", "classic", "classic","jazz","pop", "Rock", "jazz"};
    std::vector<int> plays = {150, 600, 150, 800, 1100, 2500, 100, 1000};
    for(auto data : solution(genres,plays))
        std::cout << data << " ";
}