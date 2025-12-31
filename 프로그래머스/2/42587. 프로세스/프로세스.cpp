#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int,int>> q;
    int n = priorities.size();

    for (int i = 0; i < n; i++) {
        q.push({priorities[i], i});
    }

    // 남은 문서들 중 "현재 최대 우선순위"를 쉽게 알기 위해 내림차순 정렬
    vector<int> sorted = priorities;
    sort(sorted.begin(), sorted.end(), greater<int>());

    int executed = 0; // 출력된 개수
    int k = 0;       // sorted[k] == 지금 출력되어야 하는 최대 우선순위

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        // 지금 맨 앞 문서가 현재 최대 우선순위라면 출력
        if (cur.first == sorted[k]) {
            executed++;
            if (cur.second == location) return executed;
            k++;
        } 
        // 아니면 뒤로 보냄
        else {
            q.push(cur);
        }
    }

    return -1; // 논리상 도달하지 않음
}
