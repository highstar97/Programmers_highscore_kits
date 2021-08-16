#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;

    // 위or아래로 알파벳을 맞추는 횟수를 answer에 추가
    for(int i=0; i<name.length(); i++){
        name[i] - (int)'A' > (int)'Z'+1 - name[i] ? answer += (int)'Z'+1 -name[i] : answer += name[i] - (int)'A';
    }

    // 좌or우로 최소횟수를 answer에 추가
    int len = 0;
    vector<pair<int,int>> v;
    // 연속되는 A의 시작 점과 끝 점을 v에 추가
    for(int i=0; i<name.length(); i++){
        if(name[i] == 'A'){
            int start_index = i;
            while(name[i] == 'A'){
                i++;
            }
            int last_index = --i;
            if(last_index-start_index+1 > len){
                len = last_index-start_index+1;
                v.clear();
                v.emplace_back(make_pair(start_index,last_index));
            }
            else if(last_index-start_index+1 == len)
                v.emplace_back(make_pair(start_index,last_index));
        }
    }
    int min=100;
    int max=0;
    for(auto data : v){
        if(data.first < min)
            min = data.first;
        if(data.second > max)
            max = data.second;
    }
    int shortest;
    min-1 < (name.length()-max-1) ? shortest = min-1 : shortest = name.length()-max-1;
    if(shortest < len){
        answer += (name.length()-1 + shortest - len);
    }
    else if(shortest >= len){
        answer += (name.length()-1);
    }

    return answer;
}

int main(){
    string name = "CANAAAAANAN";
    cout << solution(name);
}