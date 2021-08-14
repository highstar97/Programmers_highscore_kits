#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    vector<int> m1, m2;
    int answer;
    int dp1[money.size()];
    int dp2[money.size()-2];

    // m1 : money[0]을 사용하지 않음
    for(int i=1; i<money.size(); i++){
        m1.emplace_back(money[i]);
    }

    dp1[0] = 0;
    for(int i=1; i<=m1.size(); i++){
        if(i==1){
            dp1[i] = m1[i-1];
        }
        else{
            dp1[i] = dp1[i-1] > dp1[i-2] + m1[i-1] ? dp1[i-1] : dp1[i-2] + m1[i-1];
        }
    }
    // m2 : money[0]을 사용함
    for(int i=2; i<money.size()-1; i++){
        m2.emplace_back(money[i]);
    }

    dp2[0] = money[0];
    for(int i=1; i<m2.size()+1; i++){
        if(i==1){
            dp2[i] = m2[i-1] + money[0];
        }
        else{
            dp2[i] = dp2[i-1] > dp2[i-2] + m2[i-1] ? dp2[i-1] : dp2[i-2] + m2[i-1];
        }
    }
    answer = max(dp1[money.size()-1],dp2[money.size()-3]);
    return answer;
}

int main(){
    vector<int> money = {1,2,3,1};
    cout << solution(money);
} 