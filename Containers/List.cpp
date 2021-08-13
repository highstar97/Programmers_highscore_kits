#include <iostream>
#include <list>

using namespace std;

int main(){
    list<int> li(5,1);                      // 1 1 1 1 1
    list<int>::iterator it = li.begin();

    ++it;                                   // it = li.begin()+1 , (*it) = 1
    li.insert(it,20);                       // 1 20 1 1 1 1     it = li.begin()+2, (*it) = 1 20뒤에 오는 1을 가리킴
    li.insert(it,2,30);                     // 1 20 30 30 1 1 1 1  , it = li.begin()+2
    li.emplace(it,40);                      // 1 20 30 30 40 1 1 1 1
    
    li.emplace_front(0);                    // 0 1 20 30 30 40 1 1 1 1
    li.emplace(it,50);                      // 0 1 20 30 30 40 50 1 1 1 1
    li.emplace_back(60);                    // 0 1 20 30 30 40 50 1 1 1 1 60
    
    li.erase(it);                           // 0 1 20 30 30 40 50 1 1 1 60 
    
    for(int data : li)
        cout << data << " ";
}