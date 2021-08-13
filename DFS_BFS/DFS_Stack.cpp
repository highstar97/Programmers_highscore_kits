#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>    // sort

using namespace std;

void DFS_Stack(int start_node, vector<int> graph[], bool visited[]){
    stack<int> s;                   // �湮�� Ȯ���� stack ����
    s.push(start_node);             // stack�� ���� �湮�Ѱ����� �ϰ� visited�� true�� ���ش�.
    visited[start_node] = true;
    cout << start_node << " ";

    while(!s.empty()){
        int current_node = s.top();     // ���� ��� = stack�� top
        s.pop();                        // ���� ��尡 ���� ��� �ǵ��ư��� ����
        
        // �������� �� �湮���� ���� ��尡 �ִ��� Ȯ��
        for(int i=0; i<graph[current_node].size(); i++){
            int next_node = graph[current_node][i];  // ���� ��� = ���� ����� ���� ���
            if(visited[next_node] == false){
                s.emplace(current_node);            // s.pop�� ���־��� ������ �ٽ� emplace�ؾ��� �ǵ��ư� ���� �����
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
    int start_node = 1;             // Ž���� ������ Node
    bool visited[NODE+1] = {false}; // NODE�� �湮�ߴ��� Ȯ���ϴ� bool�� �迭, flase�� �ʱ�ȭ
    vector<int> graph [NODE+1];     // ���� ���� ������ ��� �ִ� vector(list)

    // graph ���� ����, 1-2 ��� 2-1�� ������� why? 2-1 emplace�ϰ� start�� 1�� ��� error
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

    // sort : �ϳ��� �������� ������ Ž���� ��, ���������� ���� �ʿ�
    // ���������� �������� ������ DFS_for������ ���� �߻� ����
    for(int i=1; i<NODE+1; i++)
        sort(graph[i].begin(),graph[i].end());

    // dfs_stack ����
    DFS_Stack(start_node,graph,visited);
}