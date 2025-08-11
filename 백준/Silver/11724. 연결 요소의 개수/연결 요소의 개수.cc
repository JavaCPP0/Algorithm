#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>>& arr, vector<bool>& visited, int i);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    int count = 0;
    cin >> n >> m;

    vector<vector<int>> arr(n+1);
    vector<bool> visited(n+1,false);

    for (int i = 0; i < m; i++) {
        int s,e;
        cin >> s >> e;
        arr[s].push_back(e);
        arr[e].push_back(s);

    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            count++;
            DFS(arr, visited, i);
        }
    }

    cout << count;
}

void DFS(vector<vector<int>>& arr, vector<bool>& visited, int i) {
    if (visited[i]) return;

    visited[i] = true;

    for (int num : arr[i]) {
        if (!visited[num]) {
            DFS(arr, visited, num);
        }
    }
}
