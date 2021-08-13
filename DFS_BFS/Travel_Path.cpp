#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool DFS(string now, vector<vector<string>> tickets, vector<string> &answer, vector<bool> &visited, int use_tickets){
    // ���� �湮 ������ answer�� �� �ڿ� ����
    answer.emplace_back(now);
    // ����ؾ��� Ƽ���� �� ����ߴ� => (��¥�� ���ĺ� ������ �����س����Ƿ�) ����, answer ���� �ʿ� ����
    if(use_tickets == tickets.size())   return true;
    // tickets�� �ϳ� �ϳ� Ȯ���ϸ鼭
    for(int i=0; i<tickets.size(); i++){
        // ������� ���� Ƽ�� �� ���� �湮 ���׿��� ����ϴ� Ƽ���� �ִٸ�
        if(tickets[i][0] == now && visited[i] == false){
            // Ƽ�� ���ó�� ��
            visited[i] = true;
            // ���� ���׿��� �ٽ� DFS ���� => �ȿ��� �� �ּ� ��� �ݺ��� ���� ����
            // T = true => ������ ã�Ҵ�.
            // T = false => ���� Ƽ���� �ִ�. => �ٸ� Ƽ���� ���� ����ؾ��Ѵ�.
            bool T = DFS(tickets[i][1], tickets, answer, visited, use_tickets+1);
            if(T == true)   return true;
            visited[i] = false;     // �ٽ� ����ؾ��ϹǷ� false�� ����
        }
    }
    // ���� �湮 ������ ����
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    // visited ���� : Ƽ�� ��� ���� üũ
    vector<bool> visited(tickets.size(), false);
    // ���ĺ� ������ üũ
    sort(tickets.begin(),tickets.end());
    // ICN ���� DFS ����
    DFS("ICN", tickets, answer, visited, 0);

    return answer;
}

int main(){
    vector<vector<string>> tickets ={{"ICN", "A"}, {"A", "B"}, {"B", "D"}, {"A", "C"}, {"C", "A"}};
    for(string data : solution(tickets)){
        cout << data << ", ";
    }
}