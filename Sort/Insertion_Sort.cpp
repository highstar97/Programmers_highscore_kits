#include <iostream>
#include <vector>

using namespace std;

void Insertion_Sort(vector<int>& v){
    for(int i=0; i<v.size(); i++){
        for(int j=i; j>0; j--){
            if(v[j-1] > v[j]){
                int temp = v[j];
                v[j] = v[j-1];
                v[j-1] = temp;
            }
            else break;
        }
    }
}

int main(){
    vector<int> v = {9,3,45,2,42,56,12,1};
    Insertion_Sort(v);
    for(auto data : v)
        cout << data << " ";
}