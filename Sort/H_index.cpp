#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<int> citations)
{
    int size = citations.size();
    sort(citations.begin(),citations.end());
    for(int i=size-1; i>=0; i--)
    {
        if(citations[i] < size-i)
        {
            return size-i-1;
        }
    }    
}

int main()
{
    std::vector<int> citations = {0,1,2,3,3,3};
    std::cout << solution(citations) << std::endl;
    std::cout << solution({0,2,4,5,6});
}