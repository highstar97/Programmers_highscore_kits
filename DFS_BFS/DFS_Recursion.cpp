#include <iostream>
#include <vector>
#include <algorithm>    // sort

using namespace std;

void DFS_Recursion(int start_node, vector<int> graph[], bool visited[]){
    int current_node = start_node;          // 현재 노드 = 시작 노드
    visited[current_node] = true;           // 현재 노드는 방문한 것으로 하고 visited를 true로 해준다
    cout << current_node << " ";

    // 인접 노드들 중 방문하지 않은 노드가 있는지 확인
    for(int i=0; i<graph[current_node].size(); i++){
        int next_node = graph[current_node][i];
        if(visited[next_node] == false){
            // 방문하지 않았다면 그 노드를 start_node로 DFS_Recursion() 실행 => 최대한 깊게 들어감 => 더 이상 갈 곳이 없으면 이전 노드의 인접 노드를 살펴봄
            DFS_Recursion(next_node,graph,visited);
        }
    }
}

int main(){
    const int NODE = 7;
    int start_node = 1;             // 탐색을 시작할 Node
    bool visited[NODE+1] = {false}; // NODE를 방문했는지 확인하는 bool형 배열, flase로 초기화
    vector<int> graph [NODE+1];     // 간선 연결 정보를 담고 있는 vector(list)

    // graph 간선 연결, 1-2 라면 2-1도 해줘야함 why? 2-1 emplace하고 start가 1인 경우 error
    graph[1].emplace_back(2);
    graph[1].emplace_back(3);
    graph[2].emplace_back(1);
    graph[2].emplace_back(4);
    graph[2].emplace_back(5);
    graph[3].emplace_back(1);
    graph[3].emplace_back(6);
    graph[4].emplace_back(2);
    graph[5].emplace_back(2);
    graph[5].emplace_back(7);
    graph[7].emplace_back(5);

    // sort : 하나의 정점에서 다음을 탐색할 때, 순차적으로 접근 필요
    // 순차적으로 접근하지 않으면 DFS_for문에서 오류 발생 가능
    for(int i=1; i<NODE+1; i++)
        sort(graph[i].begin(),graph[i].end());

    // DFS_Recursion 싷행
    DFS_Recursion(start_node,graph,visited);
}