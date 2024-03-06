#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers)
{
    bool IsAllZero = true;
    string Answer = "";
    vector<string> Strings;
    
    for(int number : numbers)
    {
        if(IsAllZero && number != 0)
        {
            IsAllZero = false;
        }
        Strings.emplace_back(to_string(number));
    }
    
    if(IsAllZero)
    {
        return "0";
    }
    
    sort(Strings.begin(), Strings.end(), [](const string& b, const string& f) -> bool
         {
             return f+b < b+f;
         });
    
    for(string String : Strings)
    {
        Answer += String;
    }
    
    return Answer;
}

int main()
{
    std::vector<int> numbers = {0,0,0,0};
    std::cout << solution(numbers);
}