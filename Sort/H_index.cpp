#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    for(int i=0; i<citations.size(); i++){
        int count = 0;
        for(int j=0; j<citations.size(); j++){
            if(i<= citations[j])
                count++;
        }
        if(count >= i)
            answer = i;
    }
    return answer;
}

int main(){
    vector<int> citations = {0,1,2,3,3,3};
    cout << solution(citations);
}