#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n){
    int answer = 0;

    rocks.emplace_back(0);
    rocks.emplace_back(distance);
    sort(rocks.begin(), rocks.end());

    int start = 0;
    int end = distance;
    while(start <= end){
        vector<int> temp = rocks;
        int del_rock = 0;   // 제거된 돌의 수
        int mid = (start+end)/2;
        // 0 과 distance는 포함하지 말자...
        for(int i=1; i<temp.size()-1; ){
            if(temp[i]-temp[i-1] < mid){
                vector<int>::iterator it = temp.begin()+i;
                temp.erase(it);
                del_rock++;
            }
            else{
                i++;
            }
        }
        // 마지막 돌과 distance간의 거리 판단
        if(temp[temp.size()-1] - temp[temp.size()-2] < mid){
            vector<int>::iterator it = temp.begin()+temp.size()-2;
            temp.erase(it);
            del_rock++;
        }

        if(del_rock >= n){
            end = mid-1;
            answer = mid;
        }
        else{
            start = mid+1;
        }
    }

    return answer;
}

int main(){
    int distance = 30;
    vector<int> rocks = {3,8,11,20};
    int n = 2;
    cout << solution(distance, rocks, n);
}