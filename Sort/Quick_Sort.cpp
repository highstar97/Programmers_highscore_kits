#include <iostream>
#include <vector>

using namespace std;

void Quick_Sort(vector<int>& v, int start, int end) {
    if (start >= end) return; // 원소가 1개인 경우 종료
    int pivot = start; // 피벗은 첫 번째 원소
    int left = start + 1;
    int right = end;
    while (left <= right) {
        // 피벗보다 큰 데이터를 찾을 때까지 반복
        while (left <= end && v[left] <= v[pivot]) left++;
        // 피벗보다 작은 데이터를 찾을 때까지 반복
        while (right > start && v[right] >= v[pivot]) right--;
        // 엇갈렸다면 작은 데이터와 피벗을 교체
        if (left > right) swap(v[pivot], v[right]);
        // 엇갈리지 않았다면 작은 데이터와 큰 데이터를 교체
        else swap(v[left], v[right]);
    }
    // 분할 이후 왼쪽 부분과 오른쪽 부분에서 각각 정렬 수행
    Quick_Sort(v, start, right - 1);
    Quick_Sort(v, right + 1, end);
}

int main(){
    vector<int> v = {7,0,1,2,3,4,5,6};
    Quick_Sort(v,0,v.size()-1);
    for(auto data : v)
        cout << data << " ";
}