#include <iostream>
#include <vector>
#include <algorithm>    // sort

using namespace std;

void DFS_Recursion(int start_node, vector<int> graph[], bool visited[]){
    int current_node = start_node;          // ���� ��� = ���� ���
    visited[current_node] = true;           // ���� ���� �湮�� ������ �ϰ� visited�� true�� ���ش�
    cout << current_node << " ";

    // ���� ���� �� �湮���� ���� ��尡 �ִ��� Ȯ��
    for(int i=0; i<graph[current_node].size(); i++){
        int next_node = graph[current_node][i];
        if(visited[next_node] == false){
            // �湮���� �ʾҴٸ� �� ��带 start_node�� DFS_Recursion() ���� => �ִ��� ��� �� => �� �̻� �� ���� ������ ���� ����� ���� ��带 ���캽
            DFS_Recursion(next_node,graph,visited);
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

    // DFS_Recursion ����
    DFS_Recursion(start_node,graph,visited);
}