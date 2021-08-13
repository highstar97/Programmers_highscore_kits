#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>    // sort

using namespace std;

void DFS_Stack(int start_node, vector<int> graph[], bool visited[]){
    stack<int> s;                   // 방문을 확인할 stack 생성
    s.push(start_node);             // stack에 들어가면 방문한것으로 하고 visited를 true로 해준다.
    visited[start_node] = true;
    cout << start_node << " ";

    while(!s.empty()){
        int current_node = s.top();     // 현재 노드 = stack의 top
        s.pop();                        // 인접 노드가 없을 경우 되돌아가기 위함
        
        // 인접노드들 중 방문하지 않은 노드가 있는지 확인
        for(int i=0; i<graph[current_node].size(); i++){
            int next_node = graph[current_node][i];  // 다음 노드 = 현재 노드의 인접 노드
            if(visited[next_node] == false){
                s.emplace(current_node);            // s.pop을 해주었기 때문에 다시 emplace해야지 되돌아갈 곳을 기억함
                s.emplace(next_node);
                visited[next_node] = true;
                cout << next_node << " ";
                break;
            }
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

    // dfs_stack 싷행
    DFS_Stack(start_node,graph,visited);
}