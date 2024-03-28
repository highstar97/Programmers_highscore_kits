#include <iostream>
#include <string>
#include <vector>

using namespace std;

string AEIOU = "AEIOU";

void DFS(int& Count, int &Answer, string Current, string Word)
{
    if (Current == Word)
    {
        Answer = Count;
        return;
    }

    if (Current.size() == 5)
    {
        return;
    }

    for (int i = 0; i < 5; ++i)
    {
        DFS(++Count, Answer, Current + AEIOU[i], Word);
    }
}

int solution(string Word)
{
    int Answer = 0, Count = 0;
    DFS(Count, Answer, "", Word);
    return Answer;
}

int main()
{
    cout << solution("E") << endl;
    cout << solution("AAAAE") << endl;
}