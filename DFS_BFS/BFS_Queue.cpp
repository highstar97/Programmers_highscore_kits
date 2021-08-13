#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void BFS_Queue(int start_node, vector<int> graph[], bool visited[]){
    queue<int> q;                   // 확인할 순서를 위한 queue 생성
    int current_node = start_node;  
    q.emplace(current_node);        // queue에 들어가면 방문한 것으로 하고 visited를 true로 해준다.
    visited[current_node] = true;
    cout << current_node << " ";

    while(!q.empty()){
        // DFS와 다르게 인접 노드를 한번에 모두 확인
        for(int i=0; i<graph[current_node].size(); i++){
            int next_node = graph[current_node][i];         // 다음 노드 = 현재 노드의 인접 노드
            if(visited[next_node] == false){                // 방문하지 않았다면
                q.emplace(next_node);
                visited[next_node] = true;
                cout << next_node << " ";
            }
        }
        q.pop();                    // 인접 노드를 모두 확인했다면 할 일을 마친 노드 pop()
        current_node = q.front();   // 현재 노드 = 다음 순서의 노드(이번 for문에 queue에 들어온 가장 빠른 노드) != 다음 노드
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

    // BFS_Queue 실행
    BFS_Queue(start_node,graph,visited);
}