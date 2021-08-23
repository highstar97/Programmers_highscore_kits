#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& v, int left, int right){
    vector<int> temp(v.size(),0);
    int mid = (left+right)/2;
    int i = left;
    int j = mid+1;
    int k = left;
    // ������ �ʰ����� �ʴ� ������ �ӽ� vector�� ���� ����
    while(i<=mid && j<=right){
        if(v[i]<v[j]){
            temp[k++] = v[i++];
        }
        else
            temp[k++] = v[j++];
    }
    // ��� �� ���� ������ �ʰ��Ͽ��ٸ� ���� ������ �ӽ� vector�� ����
    if(i>mid)
        while(j<=right)
            temp[k++] = v[j++];
    else
        while(i<=mid)
            temp[k++] = v[i++];
    // �ӽ� vetor�� ���� vector�� ����
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