#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_map<int, int> Hash;
    for (int i = 0; i < nums.size(); ++i)
    {
        ++Hash[nums[i]];
    }

    answer = min(nums.size() / 2, Hash.size());

    return answer;
}

int main()
{
    vector<int> nums = {3, 1, 2, 3};
    cout << solution(nums) << "\n";
    cout << solution({3, 3, 3, 2, 2, 4}) << "\n";
    cout << solution({3, 3, 3, 2, 2, 2}) << "\n";
}