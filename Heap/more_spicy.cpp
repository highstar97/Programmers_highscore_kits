#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K){
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq (scoville.begin(), scoville.end());
    while (pq.top() < K)
    {
        answer++;  
        if(pq.size() == 1)
            return -1;
        int new_scoville = pq.top();
        pq.pop();
        new_scoville += pq.top()*2;
        pq.pop();
        pq.emplace(new_scoville);
    }
    return answer;
}

int main()
{
    int K = 1000000000;
    std::vector<int> scoville = {3,100,65,43,1000000};
    std::cout << solution(scoville, K) << std::endl;
    std::cout << solution({1,2,3},11);
}