#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations)
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

int solution2(vector<int> citations)
{
    sort(citations.begin(), citations.end());
    
    int answer, start = 0, end = citations.size();

    while(start <= end)
    {
        int mid = (start+end)/2;
        
        int count = 0;
        for(int i=0; i<citations.size(); ++i)
        {
            if(citations[i] >= mid)
            {
                ++count;
            }
        }
        
        if(count >= mid)
        {
            answer = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    
    return answer;
}

int main()
{
    std::vector<int> citations = {0,1,2,3,3,3};
    std::cout << solution(citations) << std::endl;
    std::cout << solution2({0,2,4,5,6});
}