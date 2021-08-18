#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2,0);
    vector<int> v;

    for(int i=0; i<operations.size(); i++){
        // I�� �����Ѵٸ�
        if(operations[i][0] == 'I'){
            operations[i].erase(0,2);       // string�� 0�� index ���� 2�� �ε���("I ") ����, ���ڸ� ����
            v.emplace_back(stoi(operations[i]));
            sort(v.begin(),v.end());        // ���� ������������ ����
        }
        // D�� �����Ѵٸ�
        else{
            // 2�� index�� '-'��� �ּڰ� ����
            if(operations[i][2] == '-'){
                if(!v.empty()){
                    // v�� ���� ����ִٸ�, (���ĵ�)v�� �ּڰ� ����
                    v.erase(v.begin());
                }
            }
            else{
                if(!v.empty()){
                    // v�� ���� ����ִٸ�, (���ĵ�)v�� �ִ� ����
                    v.erase(v.end()-1);
                }
            }
        }
    }
    if(!v.empty()){
        answer[0] = v.back();         // �ִ� push_back
        answer[1] = v.front();        // �ּҰ� push_back
    }

    return answer;
}

int main(){
    vector<string> operations = {"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"};
    for(int data : solution(operations))
        cout << data << ' ';
}