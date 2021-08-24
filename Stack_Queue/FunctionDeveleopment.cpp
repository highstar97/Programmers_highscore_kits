#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int Size = progresses.size();
    int num = 0;      // num = �Ϸ�� progresses�� ����
    int day = 1;        // day = ��¥
    vector<int> answer;
    vector<int> finish(Size,-1);    // finish = ������ ��¥�� �����ϴ� ����
    // ��� progresses�� �Ϸ�� ������ �ݺ�
    while(num < Size){
        // �Ϸ縶�� progresses�� speed��ŭ ����
        for (int i = 0; i < Size; i++)
        {
            progresses[i] += speeds[i];
            // progresses�� 100%�� ó�� ������ finish ���Ϳ� ���� ��¥ ����
            if (progresses[i] >= 100 && finish[i] == -1){
                    finish[i] = day;
                    num++;
            }
        }
        day++;
    }
 
    // ������ �۾��� ������ �ʾҴٸ� ���� �۾��� ���� �۾� �����Ϸ� ����
    for(int i=0; i<Size-1; i++){
        if(finish[i] > finish[i+1]){
            finish[i+1] = finish[i];
        }
    }
 
    // �������� �� ���� ����� �����Ǵ��� answer�� ����
    for(int i=0; i<Size; i++){
        if(finish[i] != -1){
            // ���� ��¥�� �����Ǵ� progresses�� ���� answer�� ����
            answer.push_back(count(finish.begin(),finish.end(),finish[i]));
            // count�� ���� -1�� �ٲپ� �ٽ� count���� ���ϵ��� �Ѵ�.
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