#include <iostream>
#include <vector>
#include <math.h>       // pow()
#include <bitset>       // bitset

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    bitset <20> bitmask;        // +/- 2가지 경우이므로 bitset으로 품, 주어지는 숫자가 2~20개
    // 나올 수 있는 부분집합의 수 = pow(2,numbers.size())
    for(int i=0; i<pow(2,numbers.size());i++){
        int sum = 0;
        bitmask = i;            // bitmask = 0 ~ pow(2,numbers.size())-1
        // bitmask[j]가 0 => -1, 1 => +1 을 곱합
        // bitmask[0]은 00000000 중 가장 오른쪽 0, bitmask[1]은 00000000중 오른쪽에서 2번째
        for(int j=0; j<numbers.size(); j++){
            int multiply = 1;
            if(bitmask[j] == 0)
                multiply = -1;
            sum += numbers[j] * multiply;
        }
        if(sum == target)
            answer++;
    }
    return answer;
}

int main(){
    int target = 3;
    vector<int> numbers = {1,1,1,1,1};
    cout << solution(numbers, target);
}

/* 남이 짠 코드인데 bitset 사용 않고 bitmask로 잘풀어서 적어둠
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int size = 1 << numbers.size();

    for(int i = 1 ; i < size ; i++){
        int temp = 0;
        for(int j = 0 ; j < numbers.size() ; j++)
        {  
            if(i &(1 << j)){
                temp -= numbers[j];
            }
            else temp += numbers[j];
        }
        if(temp == target) answer++;
    }
    return answer;
}
*/