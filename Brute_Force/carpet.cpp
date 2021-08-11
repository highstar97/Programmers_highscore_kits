#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int n=1; int m=1;
    for(;;m++){
        n=m;
        while(n*m < brown+yellow)
            n++;
        if(2*n+2*m-4 == brown){
            answer.push_back(n);
            answer.push_back(m);
            break;
        }
    }
    return answer;
}

int main(){
    int brown = 8; int yellow = 1;
    for(int i : solution(brown,yellow))
        cout << i << " ";
}