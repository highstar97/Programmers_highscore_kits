#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
    vector<int> dp(32001,10);
    vector<set<int>> result;

    set<int> temp;
    result.emplace_back(temp);
    temp.emplace(N);
    result.emplace_back(temp);

    for(int i=2; i<9; i++){
        string str;
        for(int j=0; j<i; j++){
            str += "1";
        }
        int n = stoi(str);
        temp.clear();
        if(n*N <= 32000)
            temp.emplace(n*N);
        for(int j=1; j<i; ){
            for(int k=i-1; k>0; j++,k--){
                for(int data1 : result[j]){
                    for(int data2 : result[k]){
                        if(data1+data2 <= 32000)
                            temp.emplace(data1+data2);
                        if(data1-data2 >= 0)
                            temp.emplace(data1-data2);
                        if(data1 * data2 <= 32000)
                            temp.emplace(data1*data2);
                        if(data2 != 0)
                            temp.emplace(data1/data2);
                    }
                }
            }
        }
        result.emplace_back(temp);
    }
    
    for(int i=8; i>=1; i--){
        for(auto data : result[i]){
            dp[data] = i;
        }
    }
    if(dp[number] > 8)
        return -1;
    return dp[number];
}

int main(){
    int N = 5;
    int number = 12;
    cout << solution(N,number) << endl;
}