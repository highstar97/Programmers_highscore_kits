#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int MAX = 100;

// 일반적인 에라토스테네스의 체 1~MAX까지 모두 판별한다.
void Sieve_of_Eratosthenes(int Max){
    vector<bool> IsPrime(MAX+1,true);
    IsPrime[0] = false;
    IsPrime[1] = false;
    for(int i=2; i<=sqrt(Max); i++){
        if(IsPrime[i] == true){
            for(int j=2*i; j<=Max; j+=i){
                IsPrime[j] = false;
            }
        }
    }
    
    for(int i=0; i<=Max; i++)
        if(IsPrime[i] == true)
            cout << i << " ";
}

// MAX가 500근처일때는 1보다 빠르지만 MAX가 커지면 1보다 오히려 시간이 더 오래걸리더라
void Sieve_of_Eratosthenes2(int Max){
    vector<int> answer;
    for(int i=2; i<=Max; i++){
        if( i==2 || i==3 )
            answer.push_back(i);
        // 6i+1 or 6i-1 형식이면 소수 가능성 있음   
        if( i%6 == 1 || i%6 == 5 ){
            // 합성수인지 체크
            bool prime = true;
            for(int j =2; j<=sqrt(i); j++)
                if( i%j == 0 ){
                    prime = false;
                    break;  // 합성수가 판단되면 체크 중지
                }
            //check를 통과하면 소수이므로 answer에 추가
            if(prime == true)
                answer.push_back(i);
        }
    }

    for(int data : answer)
        cout << data << ' ';
}

// 어떤 수 n이 소수인지 판별하는 함수
bool Check_Prime(int n){
    if( n==1 )
        return false;
    // 2,3은 형식을 따르지 않는 소수
    if( n==2 || n==3 )
        return true;
    // 6i+1 or 6i-1 형식이면 소수 가능성 있음
    if( n%6 == 1 || n%6 == 5 ){
        // 합성수인지 체크
        for(int i =2; i<=sqrt(n); i++)
            if( n%i == 0 )
                return false;
    }
    else    // 형식을 따르지 않으면 합성수
        return false;
    // 체크를 통과하면 소수
    return true;
}

int main(){
    vector<int> arr(MAX,1);
    for(int i=0; i<MAX; i++)
        arr[i] = i+1;

    Sieve_of_Eratosthenes(MAX);
    cout << endl;

    Sieve_of_Eratosthenes2(MAX);;
    cout << endl;

    for(int i=0; i<MAX; i++)
        if( Check_Prime(arr[i]) == true )
            cout << arr[i] << ' ';
    cout << endl;
} 