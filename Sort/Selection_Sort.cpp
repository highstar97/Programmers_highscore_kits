#include <iostream>
#include <vector>

using namespace std;

void Selection_Sort(vector<int>& v){
    for(int i=0; i<v.size(); i++){
        int min_index = i;
        for(int j=i+1; j<v.size(); j++){
            if(v[min_index] > v[j])
                min_index = j;
        }
        // swap(v[i],v[min_index])
        int temp = v[i];
        v[i] = v[min_index];
        v[min_index] = temp;
    }
}

int main(){
    vector<int> v = {9,3,45,2,42,56,12,1};
    Selection_Sort(v);
    for(auto data : v)
        cout << data << " ";
}