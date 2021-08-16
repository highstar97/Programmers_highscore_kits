#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<int> distance(n+1,INF);
    // 그래프 정보 입력
    vector<vector<int>> graph(n+1);
    for(int i=0; i<edge.size(); i++){
        graph[edge[i][0]].emplace_back(edge[i][1]);
        graph[edge[i][1]].emplace_back(edge[i][0]);
    }
    // 다익스트라
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    distance[1] = 0;
    pq.emplace(make_pair(0,1));
    while(!pq.empty()){
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(distance[now] < dist) continue;
        for(int i=0; i<graph[now].size(); i++){
            int cost = dist + 1;
            if(cost < distance[graph[now][i]]){
                distance[graph[now][i]] = cost;
                pq.emplace(cost,graph[now][i]);
            }
        }
    }
    
    sort(distance.begin(),distance.end(),less<int>());

    int max;
    int i = distance.size()-1;
    while(distance[i] == INF)
        i--;
    max = distance[i];
    while(distance[i] == max){
        i--;
        answer++;
    }

    return answer;
}

int main(){
    int n = 6;
    vector<vector<int>> edge = {{3,6},{4,3},{3,2},{1,3},{1,2},{2,4},{5,2}};
    cout << solution(n,edge);
}