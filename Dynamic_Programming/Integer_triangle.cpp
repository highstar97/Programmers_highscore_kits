#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<vector<int>> answer(triangle.size(),vector<int>(triangle.size(),-1));
    answer[0][0] = triangle[0][0];

    for(int i=1; i<triangle.size(); i++){
        for(int j=0; j<triangle[i].size(); j++){
            if(j==0){
                answer[i][j] = answer[i-1][0] + triangle[i][j];
            }
            else if(j==triangle[i].size()-1){
                answer[i][j] = answer[i-1][j-1] + triangle[i][j];
            }
            else{
                answer[i][j] = max(answer[i-1][j-1]+triangle[i][j],answer[i-1][j]+triangle[i][j]);
            }
        }
    }

    int _max = 0;
    for(int i=0; i<answer.size(); i++){
        _max = max(_max,answer[answer.size()-1][i]);
    }
    return _max;
}

int main(){
    vector<vector<int>> triangle = {{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};
    cout << solution(triangle);
}