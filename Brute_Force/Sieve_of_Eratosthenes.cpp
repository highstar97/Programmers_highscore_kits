#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int MAX = 100;

// �Ϲ����� �����佺�׳׽��� ü 1~MAX���� ��� �Ǻ��Ѵ�.
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

// MAX�� 500��ó�϶��� 1���� �������� MAX�� Ŀ���� 1���� ������ �ð��� �� �����ɸ�����
void Sieve_of_Eratosthenes2(int Max){
    vector<int> answer;
    for(int i=2; i<=Max; i++){
        if( i==2 || i==3 )
            answer.push_back(i);
        // 6i+1 or 6i-1 �����̸� �Ҽ� ���ɼ� ����   
        if( i%6 == 1 || i%6 == 5 ){
            // �ռ������� üũ
            bool prime = true;
            for(int j =2; j<=sqrt(i); j++)
                if( i%j == 0 ){
                    prime = false;
                    break;  // �ռ����� �ǴܵǸ� üũ ����
                }
            //check�� ����ϸ� �Ҽ��̹Ƿ� answer�� �߰�
            if(prime == true)
                answer.push_back(i);
        }
    }

    for(int data : answer)
        cout << data << ' ';
}

// � �� n�� �Ҽ����� �Ǻ��ϴ� �Լ�
bool Check_Prime(int n){
    if( n==1 )
        return false;
    // 2,3�� ������ ������ �ʴ� �Ҽ�
    if( n==2 || n==3 )
        return true;
    // 6i+1 or 6i-1 �����̸� �Ҽ� ���ɼ� ����
    if( n%6 == 1 || n%6 == 5 ){
        // �ռ������� üũ
        for(int i =2; i<=sqrt(n); i++)
            if( n%i == 0 )
                return false;
    }
    else    // ������ ������ ������ �ռ���
        return false;
    // üũ�� ����ϸ� �Ҽ�
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