#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2,0);
    vector<int> v;

    for(int i=0; i<operations.size(); i++){
        // I로 시작한다면
        if(operations[i][0] == 'I'){
            operations[i].erase(0,2);       // string의 0번 index 부터 2개 인덱스("I ") 지움, 숫자만 남음
            v.emplace_back(stoi(operations[i]));
            sort(v.begin(),v.end());        // 값을 오름차순으로 정렬
        }
        // D로 시작한다면
        else{
            // 2번 index가 '-'라면 최솟값 삭제
            if(operations[i][2] == '-'){
                if(!v.empty()){
                    // v에 값이 들어있다면, (정렬된)v의 최솟값 삭제
                    v.erase(v.begin());
                }
            }
            else{
                if(!v.empty()){
                    // v에 값이 들어있다면, (정렬된)v의 최댓값 삭제
                    v.erase(v.end()-1);
                }
            }
        }
    }
    if(!v.empty()){
        answer[0] = v.back();         // 최댓값 push_back
        answer[1] = v.front();        // 최소값 push_back
    }

    return answer;
}

int main(){
    vector<string> operations = {"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"};
    for(int data : solution(operations))
        cout << data << ' ';
}