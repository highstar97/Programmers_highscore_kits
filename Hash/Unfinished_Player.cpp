#include <iostream>
#include <chrono>
#include <vector>
#include <unordered_map>

using namespace std;
using namespace chrono;

string solution(vector<string> participant, vector<string> completion)
{
    string answer;
    unordered_map<string, int> Hash;
    for (auto person : participant)
    {
        ++Hash[person];
    }
    for (auto person : completion)
    {
        --Hash[person];
    }
    for (auto data : Hash)
    {
        if (data.second == 1)
        {
            answer = data.first;
            break;
        }
    }
    return answer;
}

int main()
{
    vector<string> participant = {"mislav", "stanko", "mislav", "ana"};
    vector<string> completion = {"stanko", "ana", "mislav"};
    
    system_clock::time_point start, finish;
    start = system_clock::now();
    cout << solution(participant, completion) << "\n";
    finish = system_clock::now();
    cout << (finish - start).count() << " nanoseconds" << endl;
}