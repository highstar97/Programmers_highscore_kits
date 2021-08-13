#include <iostream>
#include <vector>
#include <math.h>       // pow()
#include <bitset>       // bitset

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    bitset <20> bitmask;        // +/- 2���� ����̹Ƿ� bitset���� ǰ, �־����� ���ڰ� 2~20��
    // ���� �� �ִ� �κ������� �� = pow(2,numbers.size())
    for(int i=0; i<pow(2,numbers.size());i++){
        int sum = 0;
        bitmask = i;            // bitmask = 0 ~ pow(2,numbers.size())-1
        // bitmask[j]�� 0 => -1, 1 => +1 �� ����
        // bitmask[0]�� 00000000 �� ���� ������ 0, bitmask[1]�� 00000000�� �����ʿ��� 2��°
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

/* ���� § �ڵ��ε� bitset ��� �ʰ� bitmask�� ��Ǯ� �����
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