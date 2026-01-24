#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>

using namespace std;

int DFS_count_adj(const vector<vector<int>>& adj, vector<bool>& visited, int start) {
    stack<int> st;
    st.push(start);
    visited[start] = true;

    int cnt = 0;

    while (!st.empty()) {
        int cur = st.top();
        st.pop();
        cnt++;

        for (int nxt : adj[cur]) {
            if (!visited[nxt]) {
                visited[nxt] = true;
                st.push(nxt);
            }
        }
    }

    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;

    for (int cut = 0; cut < (int)wires.size(); cut++) {
        vector<vector<int>> adj(n + 1);

        for (int i = 0; i < (int)wires.size(); i++) {
            if (i == cut) continue;
            int a = wires[i][0];
            int b = wires[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<bool> visited(n + 1, false);

        int cnt1 = DFS_count_adj(adj, visited, 1);
        int cnt2 = n - cnt1;

        answer = min(answer, abs(cnt1 - cnt2));
    }

    return answer;
}
