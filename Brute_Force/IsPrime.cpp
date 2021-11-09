#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

bool IsPrime(int n)
{
    if( n==1 )    return false;
    if( n==2 || n==3 )    return true;
    if( n%6 == 1 || n%6 == 5 )
    {
        for(int i=2; i<=sqrt(n); i++)
        {
            if(n%i == 0)    return false;
        }
    }
    else return false;
    return true;
}

int solution(std::string numbers) {
    int answer = 0;
    
}

int main(){
    std::string numbers = "011";
    std::cout << solution(numbers);
}