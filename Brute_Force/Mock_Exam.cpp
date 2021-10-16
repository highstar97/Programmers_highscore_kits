#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> solution(std::vector<int> answers)
{
    std::vector<int> answer;
    std::vector<int> student1 = {1,2,3,4,5};
    std::vector<int> student2 = {2,1,2,3,2,4,2,5};
    std::vector<int> student3 = {3,3,1,1,2,2,4,4,5,5};
    std::vector<int> score(3,0);

    for(int i=0; i<answers.size(); i++)
    {
        if(answers[i] == student1[i%student1.size()]) score[0]++;
        if(answers[i] == student2[i%student2.size()]) score[1]++;
        if(answers[i] == student3[i%student3.size()]) score[2]++;
    }

    int max = *max_element(score.begin(),score.end());

    for(int i=0; i<score.size(); i++)
    {
        if(score[i] == max)
            answer.emplace_back(i+1);
    }

    return answer;
}

int main()
{
    std::vector<int> answers = {1, 2, 3, 4, 5};
    for(auto data : solution(answers))
        std::cout << data;
}