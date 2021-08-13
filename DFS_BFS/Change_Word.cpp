#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int BFS(string begin, string target, vector<string> words){
    bool visited[50] = {false};
    queue<string> q;
    q.emplace(begin);   // q : 문자
    q.emplace("0");     // q : 문자 + 숫자
    while(!q.empty()){
        string current_word = q.front();
        q.pop();        // q : 숫자
        if(current_word == target){
            return stoi(q.front());
        }
        for(int i=0; i<words.size(); i++){
            int dif = 0;
            // 글자수가 몇 개 다른지 체크
            for(int j=0; j<current_word.size(); j++){
                if(words[i][j] != current_word[j])
                    dif++;
            }
            // 글자수 차이가 1 && 방문하지 않은 단어일 경우 q에 넣음
            if(dif == 1 && visited[i] == false){
                q.emplace(words[i]);        // q : 숫자 + 문자
                visited[i] = true;
                int num = stoi(q.front());
                num++;
                q.emplace(to_string(num));  // q : 숫자 + 문자 + (숫자+1)
            }
        }
        q.pop();                            // q : 문자 + (숫자+1) + 문자 + (숫자+1) + ....
    } 
}

int solution(string begin, string target, vector<string> words){
    // words안에 target이 있으면 BFS 실행
    for(string data : words)
        if(data == target)
            return BFS(begin, target, words);
    // target이 없으면 
    return 0;
}

int main(){
    string begin = "hit";
    string target = "hte";
    vector<string> words = {"hot", "hie", "hte", "bot", "bog", "lot", "aog", "cog"};
    cout << solution(begin, target, words);
}