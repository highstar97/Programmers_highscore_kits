#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    map<string, int> m1;
    // map<string, int, greater<string>> m1 시 내림차순 정렬

    // insert와 emplace를 이용한 삽입, pair로 삽입해야함
    m1.insert(pair<string, int>("Lee",90));
    m1.emplace(pair<string, int>("Park",100));
    m1.emplace(pair<string, int>("Kim",70));
    m1.emplace(pair<string, int>("Park",90));   // 같은 Key 값 중복 안됨, multimap에서 ㄱㄱ

    // begin(), end()를 통한 출력
    map<string,int>::iterator it;
    for(it=m1.begin(); it!=m1.end(); it++){
        // key : it->first, value : it->second
        cout << "[" << it->first << "," << it->second << "]" << endl;
        // key : (*it).first, value : (*it).second
        cout << "[" << (*it).first << "," << (*it).second << "]" << endl;
    }

    // size 출력
    cout << "size : " << m1.size() <<endl;

    // count(key)
    cout << "Park의 개수 : " << m1.count("Park") << endl;
    cout << "100점의 개수 : " << m1.count("100") << endl;   // 100은 value 이므로 0 출력

    // find(key)
    cout << "Lee의 key : " << m1.find("Lee")->first << endl;
    cout << "Lee의 value : " << m1.find("Lee")->second << endl;

    map<string, int> m2;
    
    // swap()
    m2.swap(m1);

    // empty()
    cout << boolalpha << "m1 is empty? : " << m1.empty() << endl;
    cout << "m2 is empty? : " << m2.empty() << endl;
}