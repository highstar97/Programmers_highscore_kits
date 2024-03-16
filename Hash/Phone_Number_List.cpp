#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

bool solution(vector<string> phone_book)
{
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size() - 1; i++)
    {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].length()))
        {
            return false;
        }
    }
    return true;
}

bool solution2(vector<string> phone_book)
{
    unordered_set<string> HashSet(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size(); ++i)
    {
        string str = "";
        for (int j = 0; j < phone_book[i].size(); ++j)
        {
            str += phone_book[i][j];
            if (HashSet.find(str) != HashSet.end() && str != phone_book[i])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    system_clock::time_point start, end;
    nanoseconds duration1;
    vector<string> phone_book = {"119", "97674223", "1195524421"};
    start = system_clock::now();
    cout << boolalpha << solution(phone_book);
    end = system_clock::now();
    cout << " " << (end - start).count() << "ms\n";

    start = system_clock::now();
    cout << boolalpha << solution2(phone_book);
    end = system_clock::now();
    cout << " " << (end - start).count() << "ms\n";
}