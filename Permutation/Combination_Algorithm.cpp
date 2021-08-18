#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Combination(vector<string> v, int r){
    string bitmask = "";
    for(int i=0; i<r; i++)
        bitmask += "1";
    bitmask.resize(v.size(),'0');
    
    do{
        for(int i=0; i<v.size(); i++)
            if(bitmask[i] == '1')
                cout << v[i] << ' ';
        cout << endl;
    }while(prev_permutation(bitmask.begin(),bitmask.end()));
    //bitmask�� ������������ ���ĵǾ��ֱ� ������ prev_permutation() ���
}

int main(){
    int r = 2;
    vector<string> v = {"a", "b", "c", "d", "e", "f"};
    Combination(v, r);
}