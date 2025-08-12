#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>>& arr, vector<bool>& visited, int i, int depth, bool& found);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    bool found = false;
    cin >> n >> m;

    vector<vector<int>> arr(n + 1);
    vector<bool> visited(n + 1, false);

    for (int k = 0; k < m; k++) {
        int s, e;
        cin >> s >> e;
        arr[s].push_back(e);
        arr[e].push_back(s);
    }

    for (int j = 1; j <= n; j++) {
        if (found) break; // 이미 찾았으면 더 안 탐색
        DFS(arr, visited, j, 1, found);
    }

    if (!found) cout << "0" << "\n";
    return 0;
}

void DFS(vector<vector<int>>& arr, vector<bool>& visited, int i, int depth, bool& found) {
    if (found) return; // 이미 찾았으면 종료
    visited[i] = true;

    if (depth == 5) {
        cout << "1" << "\n";
        found = true;
        visited[i] = false; // 자신이 잠근 visited 해제
        return;
    }

    for (int num : arr[i]) {
        if (!visited[num]) {
            DFS(arr, visited, num, depth + 1, found);
            if (found) {
                visited[i] = false; // 조기 종료 시 해제
                return;
            }
        }
    }

    visited[i] = false; // 백트래킹
}
