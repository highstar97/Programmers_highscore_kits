#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> Stack;

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == ')')
        {
            if (Stack.empty() || Stack.top() == ')')
            {
                return false;
            }
            Stack.pop(); // Stack.top() == '(' 뜻이므로
        }
        else
        {
            Stack.emplace('(');
        }
    }

    if (!Stack.empty())
    {
        return false;
    }
    return true;
}

int main()
{
    cout << boolalpha << solution("()()())");
}