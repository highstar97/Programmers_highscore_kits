#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> Answers)
{
    vector<int> Answer;
    vector<vector<int>> Choices = {{1, 2, 3, 4, 5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
    vector<int> Score(3, 0);

    for (int i = 0; i < Answers.size(); ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (Answers[i] == Choices[j][i % Choices[j].size()])
            {
                ++Score[j];
            }
        }
    }

    int MaxScore = *max_element(Score.begin(), Score.end());
    for (int i = 0; i < Score.size(); ++i)
    {
        if (Score[i] == MaxScore)
        {
            Answer.emplace_back(i+1);
        }
    }
    return Answer;
}

int main()
{
    vector<int> Answers = {1, 2, 3, 4, 5};
    for (auto data : solution(Answers))
    {
        cout << data;
    }
}