#include <iostream>
#include <vector>

using namespace std;

const int MAX = 200;

void DFS_Recursion(int start, vector<int> graph[], bool visited[]){
    int current_node = start;
    visited[start] = true;
    
    for(int i=0; i<graph[current_node].size(); i++){
        int next_node = graph[current_node][i];
        if(visited[next_node] == false){
            DFS_Recursion(next_node,graph,visited);
        }
    }
}

int solution(const int n, vector<vector<int>> computers) {
    int answer = 0;
    bool visited[MAX] = {false};
    vector<int> graph[n];

    // ���� ��� ���� �ֱ� , ������� �ֱ� ������ sort�� �ʿ� ����
    for(int i=0; i<computers.size(); i++){
        for(int j=0; j<computers.size(); j++){
            if( i != j && computers[i][j] == 1){
                graph[i].emplace_back(j);
            }
        }
    }
    // DFS�� ���� �湮���� ���� ��ǻ�Ͱ� �ִٸ� �װ� �ٸ� ��Ʈ��ũ
    for(int i=0; i<computers.size(); i++){
        if(visited[i] == false){
            DFS_Recursion(i,graph,visited);
            answer++;
        }
    }
    return answer;
}

int main(){
    int n = 3;
    vector<vector<int>> computers = {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};
    cout << solution(n,computers);
}