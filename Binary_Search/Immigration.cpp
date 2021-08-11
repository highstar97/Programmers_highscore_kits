#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    // sort()
    sort(times.begin(),times.end());

    // binary_search(n, times, start, end)
    long long start = 0;
    // 둘다 int형이므로 long long 으로 바꾸어 계산해야 제대로 저장됨!
    long long end = (long long)n*times[times.size()-1]; 
    while(start<=end){
        long long mid = (start+end)/2; // mid = (start+end)>>1
        long long sum = 0;
        // sum = mid 시간까지 심사관이 심사할 수 있는 사람의 수
        for(int i=0; i<times.size(); i++){
            sum += mid/times[i];
        }
        if(n <= sum){
            answer = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return answer;
}

int main(){
    int n = 1000000000;
    vector<int> times = {1000000000};
    cout << solution(n,times);
}