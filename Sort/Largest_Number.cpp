#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
    for(int i=0; i<4; i++){
        a += a;
        b += b;
    }
    a = a.substr(0,4);
    b = b.substr(0,4);
    return a > b;
}

string solution(vector<int> numbers) {
    int count = 0;
    string answer = "";
    vector<string> str_numbers;
    for(int i=0; i<numbers.size(); i++){
        if(numbers[i] == 0)
            count++;
        str_numbers.emplace_back(to_string(numbers[i]));
    }
    if(count == numbers.size()){
        answer = "0";
        return answer;
    }
    sort(str_numbers.begin(),str_numbers.end(),compare);
    for(auto data : str_numbers){
        answer += data;
    }
    return answer;
}

int main(){
    vector<int> numbers = {0,0,0,0};
    cout << solution(numbers);
}