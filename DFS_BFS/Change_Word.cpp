#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int NumOfDiff(string CurrentWord, string NextWord)
{
    int count = 0;
    int length = CurrentWord.length();
    for (int i = 0; i < length; ++i)
    {
        if (CurrentWord[i] != NextWord[i])
        {
            ++count;
        }
    }
    return count;
}

int solution(string begin, string target, vector<string> words)
{
    // target이 존재하지 words에 존재하지 않는 경우
    if (find(words.begin(), words.end(), target) == words.end())
    {
        return 0;
    }

    vector<bool> IsVisited(words.size(), false);
    queue<pair<string, int>> WordQueue; // {Word, NumOfChanges}
    WordQueue.emplace(make_pair(begin, 0));

    while (!WordQueue.empty())
    {
        string CurrentWord = WordQueue.front().first;
        int NumOfChanges = WordQueue.front().second;
        WordQueue.pop();

        if (CurrentWord == target)
        {
            return NumOfChanges;
        }

        for (int i = 0; i < words.size(); ++i)
        {
            if (IsVisited[i] == true || NumOfDiff(CurrentWord, words[i]) != 1)
            {
                continue;
            }

            IsVisited[i] = true;
            WordQueue.emplace(make_pair(words[i], NumOfChanges + 1));
        }
    }
    return 0;
}

int main()
{
    string begin = "hit";
    string target = "hte";
    vector<string> words = {"hot", "hie", "hte", "bot", "bog", "lot", "aog", "cog"};
    cout << solution(begin, target, words);
}