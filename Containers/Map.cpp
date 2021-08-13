#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    map<string, int> m1;
    // map<string, int, greater<string>> m1 �� �������� ����

    // insert�� emplace�� �̿��� ����, pair�� �����ؾ���
    m1.insert(pair<string, int>("Lee",90));
    m1.emplace(pair<string, int>("Park",100));
    m1.emplace(pair<string, int>("Kim",70));
    m1.emplace(pair<string, int>("Park",90));   // ���� Key �� �ߺ� �ȵ�, multimap���� ����

    // begin(), end()�� ���� ���
    map<string,int>::iterator it;
    for(it=m1.begin(); it!=m1.end(); it++){
        // key : it->first, value : it->second
        cout << "[" << it->first << "," << it->second << "]" << endl;
        // key : (*it).first, value : (*it).second
        cout << "[" << (*it).first << "," << (*it).second << "]" << endl;
    }

    // size ���
    cout << "size : " << m1.size() <<endl;

    // count(key)
    cout << "Park�� ���� : " << m1.count("Park") << endl;
    cout << "100���� ���� : " << m1.count("100") << endl;   // 100�� value �̹Ƿ� 0 ���

    // find(key)
    cout << "Lee�� key : " << m1.find("Lee")->first << endl;
    cout << "Lee�� value : " << m1.find("Lee")->second << endl;

    map<string, int> m2;
    
    // swap()
    m2.swap(m1);

    // empty()
    cout << boolalpha << "m1 is empty? : " << m1.empty() << endl;
    cout << "m2 is empty? : " << m2.empty() << endl;
}