#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int, int> edge;
int dijkstra(vector < vector <edge> >& mlist, vector<int>& mdistance, vector<bool>& visited, int start, int end);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector < vector <edge> > mlist(n + 1);
    vector<int> mdistance(n + 1, INT_MAX);
    vector<bool> visited(n + 1, false);

    for (int i = 0; i < m; i++) { // 가중치가 있는 인접 리스트 초기화
        int u, v, w;
        cin >> u >> v >> w;
        mlist[u].push_back(make_pair(v, w));
    }

    int start, end;
    cin >> start >> end;

    cout << dijkstra(mlist, mdistance, visited, start, end);


    return 0;
}


int dijkstra(vector < vector <edge> >& mlist, vector<int>& mdistance, vector<bool>& visited, int start, int end) {
    priority_queue<edge, vector<edge>, greater<edge>> q;

    q.push(make_pair(0, start));
    mdistance[start] = 0;

    while (!q.empty()) {
        edge current = q.top();
        q.pop();
        int c_v = current.second;

        if (!visited[c_v]) {
            visited[c_v] = true;

            for (auto i : mlist[c_v]) {
                int next = i.first;
                int value = i.second;
                if (mdistance[next] > mdistance[c_v] + value) {
                    mdistance[next] = value + mdistance[c_v];
                    q.push(make_pair(mdistance[next], next));
                }
            }
        }
    }
    return mdistance[end];
}
