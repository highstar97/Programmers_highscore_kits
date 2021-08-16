#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;
int Parent[101];
vector<pair<int,pair<int,int>>> edges;

// 특정 노드가 속한 집합 찾기
int FindParent(int x){
    if(x == Parent[x])
        return x;
    return Parent[x] = FindParent(Parent[x]);
}

// 두 노드가 속한 집합을 합치지
void UnionParent(int a, int b){
    a = FindParent(a);
    b = FindParent(b);
    if(a<b) Parent[b] = a;
    else Parent[a] = b;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<pair<int,pair<int,int>>> edges;

    // 부모 정보 자기 자신으로 초기화
    for(int i=0; i<n; i++){
        Parent[i] = i;
    }

    // 간선 정보 edges에 저장하기
    for(int i=0; i<costs.size(); i++){
        edges.emplace_back(costs[i][2],make_pair(costs[i][0],costs[i][1]));
    }

    // 간선 정보를 오름차순으로 정렬
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