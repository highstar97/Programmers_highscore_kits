#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phoneBook) {
    sort(phoneBook.begin(), phoneBook.end());
    for ( int i = 0 ; i < phoneBook.size() - 1 ; i++ ){
        if ( phoneBook[i] == phoneBook[i+1].substr(0, phoneBook[i].size()) ){
            return false;
        }
    }
    return true;
}

int main(){
    std::vector<std::string> phone_book = {"119", "97674223", "1195524421"};
    std::cout << std::boolalpha << solution(phone_book);
}