#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;
int Parent[101];
vector<pair<int,pair<int,int>>> edges;

// Ư�� ��尡 ���� ���� ã��
int FindParent(int x){
    if(x == Parent[x])
        return x;
    return Parent[x] = FindParent(Parent[x]);
}

// �� ��尡 ���� ������ ��ġ��
void UnionParent(int a, int b){
    a = FindParent(a);
    b = FindParent(b);
    if(a<b) Parent[b] = a;
    else Parent[a] = b;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<pair<int,pair<int,int>>> edges;

    // �θ� ���� �ڱ� �ڽ����� �ʱ�ȭ
    for(int i=0; i<n; i++){
        Parent[i] = i;
    }

    // ���� ���� edges�� �����ϱ�
    for(int i=0; i<costs.size(); i++){
        edges.emplace_back(costs[i][2],make_pair(costs[i][0],costs[i][1]));
    }

    // ���� ������ ������������ ����
    sort(edges.begin(),edges.end());

    // 
    for(int i=0; i<edges.size(); i++){
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if(FindParent(a) != FindParent(b)){
            UnionParent(a,b);
            answer += cost;
        }
    }

    return answer;
}

int main(){
    int n = 4;
    vector<vector<int>> costs = {{0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8}};
    cout << solution(n, costs);
}