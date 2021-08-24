#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int max_value = 0;
    int max_index = 0;
    while (true)
    { 
        // vector에서 출력된 값을 제외, 나머지 값들 중 가장 큰 값과 그 값의 위치 index를 저장
        max_value = 0;
        for (int i = answer; i < priorities.size(); i++){
            if (max_value < priorities[i])
            {
                max_value = priorities[i];
                max_index = i;
            }
        }
        // priorities 위치를 이동시킨다. 가장 큰 값을 기준으로 앞의 값들을 맨 뒤로 push_back()
        for(int i=answer; i<max_index; i++){
            priorities.push_back(*(priorities.begin()+answer));
            priorities.erase(priorities.begin()+answer);
        }
        
        // 가장 큰 값과 location의 위치가 같다면 answer++(출력 순서기 때문에 1부터 시작)해주고 loop 종료
        if(location == max_index){
            answer++;
            break;    
        }
        else{
            // 위치가 다르다면 앞으로 땡겨지기 때문에 location = location - max_index
            location -= max_index;
            // location 위치가 음수가 나오면 뒤로 갔다는 의미 => + priorities.size()를 해줌으로서 바뀐 위치 저장
            if (location < 0)
                location += priorities.size();
            else
            // location 위치가 양수가 나오면 앞으로 당겨졌다는 의미 => 가장 큰 값의 위치와의 간격 + 이전에 출력된 순서의 개수
                location += answer;
        }
        // 한번에 하나씩 무조건 출력됨
        answer++;
    }

    return answer;
}

int main(){
    vector<int> priorities = {2,3,1,4,2,1};
    int location = 3;
    cout << solution(priorities,location);
}