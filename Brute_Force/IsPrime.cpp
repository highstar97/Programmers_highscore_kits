#include <iostream>
#include <vector>
#include <string>
#include <algorithm>    // sort, next_permutation

using namespace std;

int solution(string numbers) {
    int answer = 0;
    int Size = 1;
    vector<int> number(numbers.size(),0);

    // 최대 자리수 만큼만 소수 판별 배열 생성
    for(int i=0; i<numbers.size(); i++)
        Size *= 10;
    bool IsPrime[Size];
    fill_n(IsPrime,Size,true); //모두 true로 초기화

    // 소수 판별, 에라토스테네스의 체
    IsPrime[0] = false;
    IsPrime[1] = false;
    for(int i=2; i*i<=Size; i++){
        // 만약 현재 수가 소수이면 배수들은 모두 합성수
        if(IsPrime[i] == true)
            for(int j=i+i; j<Size; j += i)
                IsPrime[j] = false;
    }

    // numbers int형으로 쪼개기
    for(int i=0; i<numbers.size(); i++){
        number[i] = numbers[i] - '0';
    }
    
    // next_permutation() 사용
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