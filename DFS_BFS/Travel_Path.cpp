#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int Depths, const string Start, string Paths, vector<bool> IsVisited, vector<string> &Answer, const vector<vector<string>> &Tickets)
{
    if (Depths >= Tickets.size())
    {
        for (int i = 0; i < Paths.size(); i += 3)
        {
            Answer.emplace_back(Paths.substr(i, 3));
        }
        return;
    }

    for (int i = 0; i < Tickets.size(); ++i)
    {
        if (Tickets[i][0] == Start && IsVisited[i] == false)
        {
            IsVisited[i] = true;
            DFS(Depths + 1, Tickets[i][1], Paths + Tickets[i][1], IsVisited, Answer, Tickets);
            IsVisited[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> Tickets)
{
    vector<string> Temp;
    vector<bool> IsVisited(Tickets.size(), false);

    sort(Tickets.begin(), Tickets.end());

    DFS(0, "ICN", "ICN", IsVisited, Temp, Tickets);

    vector<string> Answer(Temp.begin(), Temp.begin() + Tickets.size() + 1);
    return Answer;
}

int main()
{
    vector<vector<string>> tickets = {{"ICN", "A"}, {"A", "B"}, {"B", "D"}, {"A", "C"}, {"C", "A"}};
    for (string data : solution(tickets))
    {
        cout << data << ", ";
    }
}