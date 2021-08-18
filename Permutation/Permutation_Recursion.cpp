#include <iostream>
#include <vector>

using namespace std;

void swap(vector<string> &v, int i, int j){
    string temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void Permutation(vector<string> v, int i, int r){
    if (i == r){
        for(int j=0; j<i; j++){
            cout << v[j] << " ";
        }
        cout << endl;
    }
    else{
        for (int j = i; j < v.size(); j++){
            swap(v, i, j);
            Permutation(v, i + 1, r);
            swap(v, i, j);
        }
    }
}

int main()
{
    int r = 3;
    vector<string> v = {"a", "b", "c", "d"};
    Permutation(v, 0, r);
}