#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    const int SIZE = prices.size();
    for(int i=0; i<SIZE-1; i++){
        for(int j=i+1; j<SIZE; j++){
            if(prices[i] > prices[j] || j == SIZE-1){
                answer.push_back(j-i);
            }
        }
    }
    answer.push_back(0);
    return answer;
}

int main(){
    vector<int> prices = {3,5,4,2,6,7,1,2,4};
    for(int data : solution(prices))
        cout << data << " ";
}