#include <iostream>
#include <vector>
#include <algorithm>

bool solution(std::vector<std::string> phone_book) {
    std::sort(phone_book.begin(), phone_book.end());
    for(int i=0; i<phone_book.size()-1; i++){
        if(phone_book[i] == phone_book[i+1].substr(0,phone_book[i].length()))
            return false;
    }
    return true;
}

int main(){
    std::vector<std::string> phone_book = {"119", "97674223", "1195524421"};
    std::cout << std::boolalpha << solution(phone_book);
}