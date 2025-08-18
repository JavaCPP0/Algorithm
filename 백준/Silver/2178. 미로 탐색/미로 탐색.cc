#include <iostream>
#include <queue>
#include <string>

using namespace std;

static int dx[4] = { 0,1,0,-1 };
static int dy[4] = { 1,0,-1,0 };

static int n, m;

static int maze[101][101];
static bool visited[101][101] = { false };

void BFS(int x, int y);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			maze[i][j] = str[j] - '0';
		}
	}

	BFS(0, 0);

	cout << maze[n-1][m-1];

	return 0;
}

void BFS(int x,int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            
			if (!visited[nx][ny] && maze[nx][ny] == 1) {
				visited[nx][ny] = true;
				maze[nx][ny] = maze[now.first][now.second] + 1;
				q.push({ nx, ny });
			}
		}

	}

}
