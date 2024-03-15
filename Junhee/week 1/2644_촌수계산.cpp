#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> people(100, vector<int> (100));
int is_visit[100];
queue<int> bfs_q;

void bfs(int start) {
	bfs_q.push(start);
	while (!bfs_q.empty()) {
		int now = bfs_q.front();
		bfs_q.pop();
		for (int i = 0; i < 100; i++) {
			if (people[now][i] == 1 && is_visit[i] == 0) {
				bfs_q.push(i);
				is_visit[i] = is_visit[now] + 1;
			}
		}
	}
}

int main() {
	int n, m, start, end;
	cin >> n >> start >> end >> m;
	for (int i = 0; i < m; i++) {
		int child, parent;
		cin >> parent >> child;
		people[parent][child] = 1;
		people[child][parent] = 1;
	}

	bfs(start);

	if (is_visit[end]) cout << is_visit[end];
	else cout << -1;

	return 0;
}
