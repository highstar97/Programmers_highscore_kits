#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int Size = progresses.size();
    int num = 0;      // num = 완료된 progresses의 개수
    int day = 1;        // day = 날짜
    vector<int> answer;
    vector<int> finish(Size,-1);    // finish = 끝나는 날짜를 저장하는 벡터
    // 모든 progresses가 완료될 때까지 반복
    while(num < Size){
        // 하루마다 progresses가 speed만큼 증가
        for (int i = 0; i < Size; i++)
        {
            progresses[i] += speeds[i];
            // progresses가 100%를 처음 넘으면 finish 벡터에 끝난 날짜 저장
            if (progresses[i] >= 100 && finish[i] == -1){
                    finish[i] = day;
                    num++;
            }
        }
        day++;
    }
 
    // 이전의 작업이 끝나지 않았다면 뒤의 작업을 이전 작업 종료일로 연장
    for(int i=0; i<Size-1; i++){
        if(finish[i] > finish[i+1]){
            finish[i+1] = finish[i];
        }
    }
 
    // 배포마다 몇 개의 기능이 배포되는지 answer에 저장
    for(int i=0; i<Size; i++){
        if(finish[i] != -1){
            // 같은 날짜에 배포되는 progresses의 수를 answer에 저장
            answer.push_back(count(finish.begin(),finish.end(),finish[i]));
            // count한 수는 -1로 바꾸어 다시 count되지 못하도록 한다.
            for(int j=i+1; j<Size; j++){
                if(finish[j] == finish[i])
                    finish[j] = -1;
            }
        }
    }

    return answer;
}

int main(){
    vector<int> progresses = {95,90,99,99,80,99};
    vector<int> speeds = {1,1,1,1,1,1};
    for(int data : solution(progresses,speeds))
        cout << data << " ";
}