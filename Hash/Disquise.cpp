#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;
    unordered_map<string, int> HashMap;
    for (int i = 0; i < clothes.size(); ++i)
    {
        ++HashMap[clothes[i][1]];
    }

    for (auto data : HashMap)
    {
        answer *= (data.second + 1);
    }
    return answer - 1;
}

int main()
{
    vector<vector<string>> clothes = {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};
    cout << solution(clothes);
}