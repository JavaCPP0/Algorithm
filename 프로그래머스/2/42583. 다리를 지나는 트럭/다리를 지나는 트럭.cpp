#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> trucks;
    for (int w : truck_weights) trucks.push(w);

    queue<int> bridge;
    for (int i = 0; i < bridge_length; i++) bridge.push(0);

    int time = 0;
    int curWeight = 0;

    while (!trucks.empty() || curWeight > 0) {
        time++;

        // 1초 경과: 다리 맨 앞 트럭(또는 0) 내림
        curWeight -= bridge.front();
        bridge.pop();

        // 새 트럭 진입 가능하면 올리고, 아니면 0(빈 칸) 넣기
        if (!trucks.empty() && curWeight + trucks.front() <= weight) {
            int w = trucks.front();
            trucks.pop();
            bridge.push(w);
            curWeight += w;
        } else {
            bridge.push(0);
        }
    }

    return time;
}
