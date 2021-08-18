#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int count = 0;          // count = while_loop 탈출 조건
    int waiting = 0;        // waiting = 대기시간의 합
    int time = 0;           // time = 흘러가는 시간
    int running = 0;        // running = 디스크가 동작을 마칠때까지 남은 시간
    // Min_Heap 생성
    priority_queue<int, vector<int>, greater<int>> pq;
    while(true){
        // 요청시간이 되면 작업의 소요시간을 pq에 넣는다.
        if(count < jobs.size()){
            for (int i = 0; i < jobs.size(); i++){
                if (jobs[i][0] == time){
                    pq.emplace(jobs[i][1]);
                    count++;
                }
            }
        }

        // 디스크가 동작중이지 않으면
        if(running == 0){
            // pq에 요청이 들어온 작업을 확인하고 실행
            if(!pq.empty()){
                answer += pq.top();
                running = pq.top();     // 실행시간 동안 다른 작업을 수행할 수 없도록하기 위함
                pq.pop();
            }
        }
        // 디스크가 동작중이라면
        if(running > 0){
            // pq에 요청이 들어온 작업이 있는지 확인한다.
            if(!pq.empty()){
                // pq에 요청이 있다면 요청의 개수만큼 waiting을 증가시킨다.
                // waiting은 나중에 answer와 더해질 예정
                waiting += pq.size();
            }
        }

        // while문 탈출 조건
        // 수행해야할 작업이 모두 pq에 들어가고, 동작중인 작업이 없다면 => 모든 작업이 수행됬다면
        if(count == jobs.size() && running == 0)
            break;

        // 실행시간이 음수로 떨어지면 디스크가 동작중이지 않음에도 작업을 수행하지 않을 수 있음
        if(--running<0)
            running = 0;
        time++;
    }
    return (waiting + answer)/jobs.size();;
}

int main(){
    vector<vector<int>> jobs = {{0,3},{2,8},{3,4},{6,1}};
    cout << solution(jobs);
}