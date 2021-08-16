#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> lost_arr(n+1,0);
    vector<int> reserve_arr(n+1,0);
    for(int i=0; i<lost.size(); i++){
        lost_arr[lost[i]]++;
    }
    for(int i=0; i<reserve.size(); i++){
        reserve_arr[reserve[i]]++;
    }

    // 도둑 맞았는데 여분을 가지고 있으면 자기가 입음
    for(int i=1; i<=n; i++){
        if(lost_arr[i] == reserve_arr[i]){
            lost_arr[i] = 0;
            reserve_arr[i] = 0;
        }
    }

    for(int i=1; i<=n; i++){
        // 내가 여분이 있는 경우
        if(reserve_arr[i] == 1){
            // 앞의 학생이 도난당했다면 앞에 학생부터 준다.
            if(i != 1 && lost_arr[i-1] == 1){
                lost_arr[i-1] = 0;
                reserve_arr[i] = 0;
            }
            // 앞의 학생은 옷이 있고 뒤에 학생이 없으면 뒤 학생을 준다.
            else if(i != n && lost_arr[i+1] == 1){    // n+1번 학생은 존재하지 않는다.
                lost_arr[i+1] = 0;
                reserve_arr[i] = 0;
            }
        }
    }

    for(int data : lost_arr){
        if(data == 1)
            n--;
    }
    return n;
}

int main(){
    int n = 4;
    vector<int> lost = {3,1,2};
    vector<int> reserve = {2,4,3};
    cout << solution(n,lost,reserve);
}