#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0; i<commands.size(); i++){
        vector<int> temp(array.begin()+(commands[i][0]-1), array.begin()+(commands[i][1]));
        sort(temp.begin(),temp.end());
        answer.emplace_back(temp[commands[i][2]-1]);
    }
    return answer;
}

int main(){
    vector<int> array = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
    for(auto data : solution(array,commands))
        cout << data << " ";
}