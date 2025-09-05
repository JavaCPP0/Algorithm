#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int, int> edge;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E, K;

    cin >> V >> E >> K;

    vector < vector <edge> > mlist(V + 1);
    vector<int> mdistance(V + 1, INT_MAX);
    vector<bool> visited(V + 1, false);
    priority_queue<edge, vector<edge>, greater<edge>> q;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        mlist[u].push_back(make_pair(v, w));
    }

    q.push(make_pair(0, K));
    mdistance[K] = 0;
    while (!q.empty()) {
        edge current = q.top();
        q.pop();
        int c_v = current.second;
        if (visited[c_v]) continue;
        visited[c_v] = true;
        for (int i = 0; i < mlist[c_v].size(); i++) {
            edge tmp = mlist[c_v][i];
            int next = tmp.first;
            int value = tmp.second;
            if (mdistance[next] > mdistance[c_v] + value) {
                mdistance[next] = value + mdistance[c_v];
                q.push(make_pair(mdistance[next], next));
            }
        }
    }
    for (int i = 1; i <= V; i++) {
        if (visited[i])
            cout << mdistance[i] << "\n";
        else
            cout << "INF" << "\n";
    }

    return 0;
}
