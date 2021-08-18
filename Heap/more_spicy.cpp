#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K){
    int answer = 0;
    // Min_Heap ������ ���ÿ� scoville ������ Heap ������
    priority_queue<int, vector<int>, greater<int>> pq (scoville.begin(), scoville.end());

    // ���� ���� scoville ������ K �̸��̶�� ���� ����
    while (pq.top() < K){
        answer++;           // ���� ���� Ƚ�� 1ȸ �߰�
        // ������ �ϳ� ���Ƽ� �� �̻� ���Ⱑ �Ұ��� �� ���
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