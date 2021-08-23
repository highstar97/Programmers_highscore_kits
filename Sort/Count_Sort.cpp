#include <iostream>
#include <vector>

using namespace std;

Count_Sort(vector<int>& v){
    int max_value = 0;
    // v에서 최댓값을 구한다.
    for(int i=0; i<v.size(); i++)
        if(max_value < v[i])
            max_value = v[i];
    
    // 0 ~ 최댓값 까지 포함할 수 있는 벡터 count 생성
    vector<int> count(max_value+1,0);

    // count index의 값이 v에 몇 개 있는지 저장
    for(int i=0; i<v.size(); i++){
        count[v[i]]++;
    }

    int index = 0;
    // count에 저장된 개수만큼 v에 덮어 씌움
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