#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> Answer;
    unordered_map<string, int> SumOfPlays;
    unordered_map<string, vector<pair<int, int>>> IndexAndPlaysOfGenres; // {genre, {{150,0},{150,2},{800,3}}}

    for (int i = 0; i < genres.size(); ++i)
    {
        SumOfPlays[genres[i]] += plays[i];
        IndexAndPlaysOfGenres[genres[i]].emplace_back(make_pair(i, plays[i]));
    }

    vector<pair<string, int>> SumOfPlaysVector(SumOfPlays.begin(), SumOfPlays.end());
    sort(SumOfPlaysVector.begin(), SumOfPlaysVector.end(), [](const pair<string, int> &b, const pair<string, int> &f) -> bool
         { return f.second < b.second; });

    for (auto data : SumOfPlaysVector)
    {
        vector<pair<int, int>> IndexAndPlaysVector = IndexAndPlaysOfGenres[data.first];
        sort(IndexAndPlaysVector.begin(), IndexAndPlaysVector.end(), [](const pair<int, int> &b, const pair<int, int> &f) -> bool
             { return f.second < b.second; });
        int count = 0;
        for (auto IndexAndPlays : IndexAndPlaysVector)
        {
            if (count >= 2)
            {
                break;
            }
            Answer.emplace_back(IndexAndPlays.first);
            ++count;
        }
    }
    return Answer;
}

int main()
{
    vector<string> genres = {"classic", "pop", "classic", "classic", "jazz", "pop", "Rock", "jazz"};
    vector<int> plays = {150, 600, 150, 800, 1100, 2500, 1000, 1000};
    for (auto data : solution(genres, plays))
    {
        cout << data << " ";
    }
}