#include <iostream>
#include <queue>
#include <stack>


using namespace std;

int n, m, v;
queue<int> bfs_q;
int node[1001][1001];
int dfs_visit[1001];
int bfs_visit[1001];

void dfs(int curr) {
	dfs_visit[curr] = 1;
	cout << curr << " ";
	for (int i = 0; i <= n; i++) {
		if (node[curr][i] == 1 && dfs_visit[i] == 0) {
			dfs_visit[i] = 1;
			dfs(i);
		}
	}
}

void bfs(int start) {
	bfs_q.push(start);
	bfs_visit[start] = 1;
	while (!bfs_q.empty()) {
		int curr = bfs_q.front();
		cout << curr << " ";
		bfs_q.pop();
		for (int i = 0; i <= n; i++) {
			if (node[curr][i] == 1 && bfs_visit[i] == 0) {
				bfs_visit[i] = 1;
				bfs_q.push(i);
			}
		}
	}
}

int main() {
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		node[s][e] = 1;
		node[e][s] = 1;
	}

	dfs(v);
	cout << endl;
	bfs(v);

	return 0;
}
