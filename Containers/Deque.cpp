#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> dq1(5,1);     // 1 1 1 1 1

    // insert(��ġ, (����), ��)
    dq1.insert(dq1.begin()+1,20);               // 1 20 1 1 1 1
    dq1.insert(dq1.begin()+2,2,30);             // 1 20 30 30 1 1 1 1
    // emplace(��ġ, (����), ��)
    dq1.emplace(dq1.begin()+4,40);              // 1 20 30 30 40 1 1 1 1

    dq1.emplace_front(0);                       // 0 1 20 30 30 40 1 1 1 1
    dq1.emplace_back(50);                       // 0 1 20 30 30 40 1 1 1 1 50
    // erase(���� ��ġ(����O),(���� ��ġ(����x)))
    dq1.erase(dq1.begin()+6);                   // 0 1 20 30 30 40 1 1 1 50
    dq1.erase(dq1.begin()+6,dq1.begin()+9);     // 0 1 20 30 30 40 50

    for(int data : dq1)
        cout << data << " ";
}