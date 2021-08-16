#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    vector<int>::iterator it = people.begin();

    sort(people.begin(),people.end(),greater<int>());  // 내림차순 정렬

    int min = 0;
    int max = people.size()-1;
    while(min < max){
        if(people[min]+people[max] <= limit)
            max--;
        min++;
        answer++;
    }
    if(min == max)
        answer++;

    return answer;
}

int main(){
    int limit = 80;
    vector<int> people ={30,30,50,50,70};
    cout << solution(people,limit);
}