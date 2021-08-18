#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K){
    int answer = 0;
    // Min_Heap 생성과 동시에 scoville 정보를 Heap 안으로
    priority_queue<int, vector<int>, greater<int>> pq (scoville.begin(), scoville.end());

    // 가장 작은 scoville 지수가 K 미만이라면 섞기 진행
    while (pq.top() < K){
        answer++;           // 섞기 진행 횟수 1회 추가
        // 음식이 하나 남아서 더 이상 섞기가 불가능 할 경우
        if(pq.size() == 1)
            return -1;
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();
        pq.emplace(min1 + (2 * min2));
    }

    return answer;
}

int main()
{
    vector<int> scoville = {3,100,65,43,1000000};
    int K = 1000000000;
    cout << solution(scoville, K);
}