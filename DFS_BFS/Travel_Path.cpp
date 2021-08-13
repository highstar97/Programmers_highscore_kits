#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool DFS(string now, vector<vector<string>> tickets, vector<string> &answer, vector<bool> &visited, int use_tickets){
    // 현재 방문 공항을 answer의 맨 뒤에 삽입
    answer.emplace_back(now);
    // 사용해야할 티켓을 다 사용했다 => (어짜피 알파벳 순으로 정렬해놨으므로) 정답, answer 수정 필요 없음
    if(use_tickets == tickets.size())   return true;
    // tickets을 하나 하나 확인하면서
    for(int i=0; i<tickets.size(); i++){
        // 사용하지 않은 티켓 중 현재 방문 공항에서 출발하는 티켓이 있다면
        if(tickets[i][0] == now && visited[i] == false){
            // 티켓 사용처리 후
            visited[i] = true;
            // 도착 공항에서 다시 DFS 실행 => 안에서 위 주석 계속 반복해 나갈 것임
            // T = true => 정답을 찾았다.
            // T = false => 남는 티켓이 있다. => 다른 티켓을 먼저 사용해야한다.
            bool T = DFS(tickets[i][1], tickets, answer, visited, use_tickets+1);
            if(T == true)   return true;
            visited[i] = false;     // 다시 사용해야하므로 false로 변경
        }
    }
    // 현재 방문 공항을 빼냄
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    // visited 벡터 : 티켓 사용 여부 체크
    vector<bool> visited(tickets.size(), false);
    // 알파벳 순으로 체크
    sort(tickets.begin(),tickets.end());
    // ICN 부터 DFS 시작
    DFS("ICN", tickets, answer, visited, 0);

    return answer;
}

int main(){
    vector<vector<string>> tickets ={{"ICN", "A"}, {"A", "B"}, {"B", "D"}, {"A", "C"}, {"C", "A"}};
    for(string data : solution(tickets)){
        cout << data << ", ";
    }
}