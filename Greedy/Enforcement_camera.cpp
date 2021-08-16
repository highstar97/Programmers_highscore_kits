#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    vector<vector<int>>::iterator it;

    // 먼저 나가는 순으로 정렬
    sort(routes.begin(), routes.end(), compare);

    // 카메라가 범위안에 있으면 제거
    int min = 0;
    while(true){
        it = routes.begin() + min;
        if(it == routes.end())
            break;
        for(int i=min+1; i<routes.size(); i++){
            if( routes[i][0] <= (*it)[1] && (*it)[1] <= routes[i][1] ){
                vector<vector<int>>::iterator it2 = routes.begin() + i;
                routes.erase(it2);
                i--;
            }
        }
        answer++;
        min++;
    }

    return answer;
}

int main(){
    vector<vector<int>> routes = {{-100,100},{50,170},{150,200},{-50,-10},{10,20},{30,40}};
    cout << solution(routes);
}