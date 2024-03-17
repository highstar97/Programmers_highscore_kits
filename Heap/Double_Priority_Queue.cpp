#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations)
{
    multiset<int> Set;
    for (string operation : operations)
    {
        if (operation[0] == 'I')
        {
            Set.emplace(stoi(operation.substr(2)));
        }
        else if (operation[2] == '1' && !Set.empty())
        {
            Set.erase(--Set.end());
        }
        else if (!Set.empty())
        {
            Set.erase(Set.begin());
        }
    }

    if (Set.empty())
    {
        return {0, 0};
    }
    else
    {
        return {*(--Set.end()), *Set.begin()};
    }
}

int main()
{
    vector<string> operations = {"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"};
    for (int data : solution(operations))
        cout << data << ' ';
}