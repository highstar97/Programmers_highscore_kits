#include <iostream>
#include <vector>
#include <queue>

int solution(int bridge_length, int weight, std::vector<int> truck_weights) {
    int time = 0;
    int on_bridge_weight = 0;
    std::queue<int> wait;
    std::queue<std::pair<int,int>> on_bridge;

    for(auto data : truck_weights)
        wait.emplace(data);
    
    while(!wait.empty())
    {
        if(on_bridge_weight + wait.front() <= weight)
        {
            on_bridge.emplace(std::make_pair(wait.front(),time));
            on_bridge_weight += wait.front();
            wait.pop();
            time++;
        }
        else
        {
            // 시간은 줄어들 수 없다.
            time = std::max(time,on_bridge.front().second + bridge_length);
            on_bridge_weight -= on_bridge.front().first;
            on_bridge.pop();
        }
    }
    while(!on_bridge.empty())
    {
        time = on_bridge.front().second + bridge_length;
        on_bridge.pop();
    }
    return time+1;
}

int main(){
    int bridge_length = 2;
    int weight = 10;
    std::vector<int> truck_weights = {7,4,5,6};
    //std::cout << solution(bridge_length, weight, truck_weights);
    //std::cout << std::endl << solution(100,100,{10, 10, 10, 10, 10, 10, 10, 10, 10, 10});
    std::cout << std::endl << solution(5,5,{2,2,2,2,1,1,1,1,1});
}