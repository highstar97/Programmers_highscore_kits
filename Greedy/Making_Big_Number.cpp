#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    for(int i=0; i<number.length()-1; i++){
        if(k == 0)
            return number;
        if(number[i] < number[i+1]){
            number.erase(i,1);
            if(i!=0)
                i -= 2;
            else
                i -= 1;
            k--;
        }
    
    }

    // k�� ���� ��� , ���� ���� ������������ ���ĵǾ� �ִ�.
    number = number.substr(0,(number.length()-k));

    return number;
}

int main(){
    int k = 9;
    string number = "4177252841";
    cout << solution(number,k);
}