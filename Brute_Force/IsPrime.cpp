#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <algorithm>

using namespace std;

bool IsPrime(int n)
{
    if (n == 1)
    {
        return false;
    }
    if (n == 2 || n == 3)
    {
        return true;
    }
    if (n % 6 == 1 || n % 6 == 5)
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
    return true;
}

int solution(string Numbers)
{
    int Answer = 0;
    set<int> Set;
    vector<char> Number(Numbers.begin(), Numbers.end());

    sort(Number.begin(), Number.end());

    for (int r = 1; r <= Numbers.size(); ++r)
    {
        do
        {
            string str = "";
            for (int i = 0; i < r; ++i)
            {
                str += Number[i];
            }
            Set.emplace(stoi(str));
            reverse(Number.begin() + r, Number.end());
        } while (next_permutation(Number.begin(), Number.end()));
    }

    for (auto data : Set)
    {
        if (IsPrime(data))
        {
            ++Answer;
        }
    }
    return Answer;
}

int main()
{
    string Numbers = "011";
    cout << solution(Numbers);
}