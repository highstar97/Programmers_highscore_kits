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

    // ���� �¾Ҵµ� ������ ������ ������ �ڱⰡ ����
    for(int i=1; i<=n; i++){
        if(lost_arr[i] == reserve_arr[i]){
            lost_arr[i] = 0;
            reserve_arr[i] = 0;
        }
    }

    for(int i=1; i<=n; i++){
        // ���� ������ �ִ� ���
        if(reserve_arr[i] == 1){
            // ���� �л��� �������ߴٸ� �տ� �л����� �ش�.
            if(i != 1 && lost_arr[i-1] == 1){
                lost_arr[i-1] = 0;
                reserve_arr[i] = 0;
            }
            // ���� �л��� ���� �ְ� �ڿ� �л��� ������ �� �л��� �ش�.
            else if(i != n && lost_arr[i+1] == 1){    // n+1�� �л��� �������� �ʴ´�.
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