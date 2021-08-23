#include <iostream>
#include <vector>

using namespace std;

Count_Sort(vector<int>& v){
    int max_value = 0;
    // v���� �ִ��� ���Ѵ�.
    for(int i=0; i<v.size(); i++)
        if(max_value < v[i])
            max_value = v[i];
    
    // 0 ~ �ִ� ���� ������ �� �ִ� ���� count ����
    vector<int> count(max_value+1,0);

    // count index�� ���� v�� �� �� �ִ��� ����
    for(int i=0; i<v.size(); i++){
        count[v[i]]++;
    }

    int index = 0;
    // count�� ����� ������ŭ v�� ���� ����
    for(int i=0; i<max_value+1; i++){
        for(int j=0; j<count[i]; j++){
            v[index] = i;
            index++;
        }
    }
}

int main(){
    vector<int> v = {9,3,45,2,42,56,12,1};
    Count_Sort(v);
    for(auto data : v)
        cout << data << " ";
}