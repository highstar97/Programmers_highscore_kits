#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Permutation(vector<string> v, int r){
    //next_permutation ����Ϸ��� �������� ���� �ʼ�!
    sort(v.begin(), v.end());

    do{
        for(auto it = v.begin(); it < v.begin()+r; it++)
            cout << *it << ' ';
        cout << endl;
        reverse(v.begin()+r, v.end());
    }while(next_permutation(v.begin(),v.end()));
}

int main(){
    int r = 4;
    vector<string> v = {"a", "b", "c", "d", "e"};
    Permutation(v, r);
}