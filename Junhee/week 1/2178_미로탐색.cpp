#include <iostream>
#include <string>
#include <queue>

using namespace std;
int map[100][100];
int is_visit[100][100];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> bfs_q;
int n, m;

void bfs() {
	while (!bfs_q.empty()) {
		int x = bfs_q.front().first;
		int y = bfs_q.front().second;
		bfs_q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			else if (map[nx][ny] == 1 && is_visit[nx][ny] == 0) {
				bfs_q.push(make_pair(nx, ny));
				is_visit[nx][ny] = is_visit[x][y] + 1;
			}
		}
	}
}





int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string line_s;
		cin >> line_s;
		for (int j = 0; j < line_s.size(); j++) {
			if (line_s[j] == '1') map[i][j] = 1;
			else map[i][j] = 0;
		}
	}
	is_visit[0][0] = 1;
	bfs_q.push(make_pair(0, 0));
	bfs();

	cout << is_visit[n - 1][m - 1];

	return 0;
}
