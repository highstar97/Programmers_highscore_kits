#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int num_of_truck = truck_weights.size();
    int i = 1;          // i = ��� �ð�
    int up = 0;         // up = �ٸ��� �ö� Ʈ���� ��
    int down = 0;       // down = �ٸ����� ������ Ʈ���� ��
    int onbridge = 0;   // onbridge = �ٸ��� �ö� Ʈ���� ������ ��
    queue<int> ing;
    vector<int> time(num_of_truck,0);   // time[num_of_truck]�� ���ϴ� ��

    // �ٸ��� Ʈ���� �� �ø� �� ���� (timd[num_of_truck]���� �˸� �ǹǷ�)
    while(up != num_of_truck){
        // Ʈ���� ���� �ð��̸� �ٸ� �� Ʈ�� ���Ը� ���߰� Ʈ���� ������.
        if (i == time[down])
        {
            onbridge -= ing.front();
            ing.pop();
            down++;    // ���� Ʈ���� ���� �ð��� ��ٸ���.
        }
        
        // �ٸ� �� Ʈ�� ���� + �ö� Ʈ�� ���� <= �ѵ� ����
        if (onbridge + truck_weights[up] <= weight)
        {
            // Ʈ���� �ٸ��� �ø���.
            onbridge += truck_weights[up];
            ing.push(truck_weights[up]);

            // Ʈ���� �ٸ����� ���� �ð��� üũ
            time[up] = i + bridge_length;
            
            up++;
        }
        
        i++;
    }

    return time[num_of_truck-1];
}

int main(){
    int bridge_length = 2;
    int weight = 10;
    std::vector<int> truck_weights = {7,4,5,6};
    std::cout << solution(bridge_length,weight,truck_weights);
}