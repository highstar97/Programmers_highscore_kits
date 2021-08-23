#include <iostream>
#include <vector>

using namespace std;

void Quick_Sort(vector<int>& v, int start, int end) {
    if (start >= end) return; // ���Ұ� 1���� ��� ����
    int pivot = start; // �ǹ��� ù ��° ����
    int left = start + 1;
    int right = end;
    while (left <= right) {
        // �ǹ����� ū �����͸� ã�� ������ �ݺ�
        while (left <= end && v[left] <= v[pivot]) left++;
        // �ǹ����� ���� �����͸� ã�� ������ �ݺ�
        while (right > start && v[right] >= v[pivot]) right--;
        // �����ȴٸ� ���� �����Ϳ� �ǹ��� ��ü
        if (left > right) swap(v[pivot], v[right]);
        // �������� �ʾҴٸ� ���� �����Ϳ� ū �����͸� ��ü
        else swap(v[left], v[right]);
    }
    // ���� ���� ���� �κа� ������ �κп��� ���� ���� ����
    Quick_Sort(v, start, right - 1);
    Quick_Sort(v, right + 1, end);
}

int main(){
    vector<int> v = {7,0,1,2,3,4,5,6};
    Quick_Sort(v,0,v.size()-1);
    for(auto data : v)
        cout << data << " ";
}