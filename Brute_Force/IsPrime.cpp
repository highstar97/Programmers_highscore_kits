#include <iostream>
#include <vector>
#include <string>
#include <algorithm>    // sort, next_permutation

using namespace std;

int solution(string numbers) {
    int answer = 0;
    int Size = 1;
    vector<int> number(numbers.size(),0);

    // �ִ� �ڸ��� ��ŭ�� �Ҽ� �Ǻ� �迭 ����
    for(int i=0; i<numbers.size(); i++)
        Size *= 10;
    bool IsPrime[Size];
    fill_n(IsPrime,Size,true); //��� true�� �ʱ�ȭ

    // �Ҽ� �Ǻ�, �����佺�׳׽��� ü
    IsPrime[0] = false;
    IsPrime[1] = false;
    for(int i=2; i*i<=Size; i++){
        // ���� ���� ���� �Ҽ��̸� ������� ��� �ռ���
        if(IsPrime[i] == true)
            for(int j=i+i; j<Size; j += i)
                IsPrime[j] = false;
    }

    // numbers int������ �ɰ���
    for(int i=0; i<numbers.size(); i++){
        number[i] = numbers[i] - '0';
    }
    
    // next_permutation() ���
    string result;
    sort(number.begin(), number.end());
    for(int r=0; r<=numbers.size(); r++){
        do
        {
            result.clear();
            for (int i = 0; i < r; i++)
                result += to_string(number[i]);
            if(result != ""){
                if(result[0] != '0'){
                    int a = stoi(result);
                    if (IsPrime[a] == true)
                        answer++;
                }
            }
            reverse(number.begin() + r, number.end());
        } while (next_permutation(number.begin(), number.end()));
    }
    return answer;
}

int main(){
    string numbers = "011";
    cout << solution(numbers) << endl;
}