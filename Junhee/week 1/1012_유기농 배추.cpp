#include <iostream>
#include <algorithm>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int map[50][50];

void dfs(int x, int y) {
	map[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i]; int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= 50 || ny >= 50) continue;
		if (map[nx][ny] == 1)
			dfs(nx, ny);
	}
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int m, n, k;
		int cnt = 0;
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++) {
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}

		for (int a = 0; a < m; a++) {
			for (int b = 0; b < n; b++) {
				if (map[a][b] == 1) {
					dfs(a, b);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}

	return 0;
}
