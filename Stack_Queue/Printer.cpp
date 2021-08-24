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
        // vector���� ��µ� ���� ����, ������ ���� �� ���� ū ���� �� ���� ��ġ index�� ����
        max_value = 0;
        for (int i = answer; i < priorities.size(); i++){
            if (max_value < priorities[i])
            {
                max_value = priorities[i];
                max_index = i;
            }
        }
        // priorities ��ġ�� �̵���Ų��. ���� ū ���� �������� ���� ������ �� �ڷ� push_back()
        for(int i=answer; i<max_index; i++){
            priorities.push_back(*(priorities.begin()+answer));
            priorities.erase(priorities.begin()+answer);
        }
        
        // ���� ū ���� location�� ��ġ�� ���ٸ� answer++(��� ������ ������ 1���� ����)���ְ� loop ����
        if(location == max_index){
            answer++;
            break;    
        }
        else{
            // ��ġ�� �ٸ��ٸ� ������ �������� ������ location = location - max_index
            location -= max_index;
            // location ��ġ�� ������ ������ �ڷ� ���ٴ� �ǹ� => + priorities.size()�� �������μ� �ٲ� ��ġ ����
            if (location < 0)
                location += priorities.size();
            else
            // location ��ġ�� ����� ������ ������ ������ٴ� �ǹ� => ���� ū ���� ��ġ���� ���� + ������ ��µ� ������ ����
                location += answer;
        }
        // �ѹ��� �ϳ��� ������ ��µ�
        answer++;
    }

    return answer;
}

int main(){
    vector<int> priorities = {2,3,1,4,2,1};
    int location = 3;
    cout << solution(priorities,location);
}