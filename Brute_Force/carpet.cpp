#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    int Row, Col;
    int Sum = brown + yellow;
    // (Row + Col)*2 - 4  = brown
    // Row * Col = brown + yellow
    for (Col = 1; Col * Col <= Sum; ++Col)
    {
        for (Row = 1;; ++Row)
        {
            if (Row > Sum)
            {
                break;
            }
    
            if (Row * Col == Sum && Row + Col == (brown + 4) / 2)
            {
                return {Row, Col};
            }
        }
    }
}

int main()
{
    int brown = 10;
    int yellow = 2;
    for (int i : solution(brown, yellow))
    {
        cout << i << " ";
    }
}