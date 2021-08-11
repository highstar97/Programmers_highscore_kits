#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    // 학생 답안지 vector와 점수 vector
    vector<int> stu1 = {1,2,3,4,5};
    vector<int> stu2 = {2,1,2,3,2,4,2,5};
    vector<int> stu3 = {3,3,1,1,2,2,4,4,5,5};
    vector<int> score = {0,0,0};
    
    // 정답여부 확인
    for(int i=0; i<answers.size(); i++){
        if(answers[i] == stu1[i%stu1.size()]) score[0]++;
        if(answers[i] == stu2[i%stu2.size()]) score[1]++;
        if(answers[i] == stu3[i%stu3.size()]) score[2]++;
    }
    
    // 최대값 구하기 ( #include <algorithm> 필요, max_element의 반환값은 주소이므로 * 사용)
    int max = *max_element(score.begin(),score.end());
    
    // 최대 점수 학생 answer vector에 push_back()
    for(int i = 0; i<3; i++)
        if(max == score[i])
            answer.push_back(i+1);
    
    return answer;
}

int main(){
    vector<int> answers = {1,3,2,4,2};
    vector<int> answer = solution(answers);
    for(int i : answer)
        cout << i << " ";
}