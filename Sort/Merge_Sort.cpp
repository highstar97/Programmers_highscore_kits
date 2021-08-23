#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& v, int left, int right){
    vector<int> temp(v.size(),0);
    int mid = (left+right)/2;
    int i = left;
    int j = mid+1;
    int k = left;
    // 범위를 초과하지 않는 선에서 임시 vector에 값을 넣음
    while(i<=mid && j<=right){
        if(v[i]<v[j]){
            temp[k++] = v[i++];
        }
        else
            temp[k++] = v[j++];
    }
    // 어느 한 곳이 범위를 초과하였다면 남은 값들을 임시 vector에 넣음
    if(i>mid)
        while(j<=right)
            temp[k++] = v[j++];
    else
        while(i<=mid)
            temp[k++] = v[i++];
    // 임시 vetor에 값을 vector에 저장
    for(int i=left; i<=right; i++)
        v[i] = temp[i];
}

void Merge_Sort(vector<int>& v, int left, int right){
    if(left < right){
        int mid = (left+right)/2;
        Merge_Sort(v,left,mid);     
        Merge_Sort(v,mid+1,right);  
        merge(v,left,right);
    }
}

int main(){
    vector<int> v = {9,3,45,2,42,56,12,1};
    Merge_Sort(v,0,v.size()-1);
    for(auto data : v)
        cout << data << " ";
}