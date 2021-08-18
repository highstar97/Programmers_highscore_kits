#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int count = 0;          // count = while_loop Ż�� ����
    int waiting = 0;        // waiting = ���ð��� ��
    int time = 0;           // time = �귯���� �ð�
    int running = 0;        // running = ��ũ�� ������ ��ĥ������ ���� �ð�
    // Min_Heap ����
    priority_queue<int, vector<int>, greater<int>> pq;
    while(true){
        // ��û�ð��� �Ǹ� �۾��� �ҿ�ð��� pq�� �ִ´�.
        if(count < jobs.size()){
            for (int i = 0; i < jobs.size(); i++){
                if (jobs[i][0] == time){
                    pq.emplace(jobs[i][1]);
                    count++;
                }
            }
        }

        // ��ũ�� ���������� ������
        if(running == 0){
            // pq�� ��û�� ���� �۾��� Ȯ���ϰ� ����
            if(!pq.empty()){
                answer += pq.top();
                running = pq.top();     // ����ð� ���� �ٸ� �۾��� ������ �� �������ϱ� ����
                pq.pop();
            }
        }
        // ��ũ�� �������̶��
        if(running > 0){
            // pq�� ��û�� ���� �۾��� �ִ��� Ȯ���Ѵ�.
            if(!pq.empty()){
                // pq�� ��û�� �ִٸ� ��û�� ������ŭ waiting�� ������Ų��.
                // waiting�� ���߿� answer�� ������ ����
                waiting += pq.size();
            }
        }

        // while�� Ż�� ����
        // �����ؾ��� �۾��� ��� pq�� ����, �������� �۾��� ���ٸ� => ��� �۾��� ������ٸ�
        if(count == jobs.size() && running == 0)
            break;

        // ����ð��� ������ �������� ��ũ�� ���������� �������� �۾��� �������� ���� �� ����
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