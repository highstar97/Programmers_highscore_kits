#include <iostream>
#include <vector>
#include <map>

using namespace std;

Count_Sort_Map(vector<int>& v){
    map<int,int> m;
    // map�� v[i]�� ���� ���� ������ ����
    for(int i=0; i<v.size(); i++){
        m[v[i]]++;
    }

    int index = 0;
    for(auto data : m){
        for(int i=0; i<data.second; i++){
            v[index] = data.first;
            index++;
        }
    }
}

int main(){
    vector<int> v = {9,9,3,45,2,1,42,56,12,1};
    Count_Sort_Map(v);
    for(auto data : v)
        cout << data << " ";
}