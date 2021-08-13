#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int BFS(string begin, string target, vector<string> words){
    bool visited[50] = {false};
    queue<string> q;
    q.emplace(begin);   // q : ����
    q.emplace("0");     // q : ���� + ����
    while(!q.empty()){
        string current_word = q.front();
        q.pop();        // q : ����
        if(current_word == target){
            return stoi(q.front());
        }
        for(int i=0; i<words.size(); i++){
            int dif = 0;
            // ���ڼ��� �� �� �ٸ��� üũ
            for(int j=0; j<current_word.size(); j++){
                if(words[i][j] != current_word[j])
                    dif++;
            }
            // ���ڼ� ���̰� 1 && �湮���� ���� �ܾ��� ��� q�� ����
            if(dif == 1 && visited[i] == false){
                q.emplace(words[i]);        // q : ���� + ����
                visited[i] = true;
                int num = stoi(q.front());
                num++;
                q.emplace(to_string(num));  // q : ���� + ���� + (����+1)
            }
        }
        q.pop();                            // q : ���� + (����+1) + ���� + (����+1) + ....
    } 
}

int solution(string begin, string target, vector<string> words){
    // words�ȿ� target�� ������ BFS ����
    for(string data : words)
        if(data == target)
            return BFS(begin, target, words);
    // target�� ������ 
    return 0;
}

int main(){
    string begin = "hit";
    string target = "hte";
    vector<string> words = {"hot", "hie", "hte", "bot", "bog", "lot", "aog", "cog"};
    cout << solution(begin, target, words);
}