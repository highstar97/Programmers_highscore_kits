#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int num_of_truck = truck_weights.size();
    int i = 1;          // i = 경과 시간
    int up = 0;         // up = 다리에 올라간 트럭의 수
    int down = 0;       // down = 다리에서 내려온 트럭의 수
    int onbridge = 0;   // onbridge = 다리에 올라간 트럭의 무게의 합
    queue<int> ing;
    vector<int> time(num_of_truck,0);   // time[num_of_truck]이 원하는 값

    // 다리에 트럭을 다 올릴 때 까지 (timd[num_of_truck]값만 알면 되므로)
    while(up != num_of_truck){
        // 트럭이 내릴 시간이면 다리 위 트럭 무게를 낮추고 트럭을 내린다.
        if (i == time[down])
        {
            onbridge -= ing.front();
            ing.pop();
            down++;    // 다음 트럭의 내릴 시간을 기다린다.
        }
        
        // 다리 위 트럭 무게 + 올라갈 트럭 무게 <= 한도 무게
        if (onbridge + truck_weights[up] <= weight)
        {
            // 트럭을 다리에 올린다.
            onbridge += truck_weights[up];
            ing.push(truck_weights[up]);

            // 트럭이 다리에서 내릴 시간을 체크
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