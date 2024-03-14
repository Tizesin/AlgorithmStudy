#include <iostream>
#include <vector>

using namespace std;

vector <vector<int>> graph;
bool is_visit[1000];

void dfs(int node) {
	is_visit[node] = true;
	for (int i = 0; i < graph[node].size(); i++) {
		if (!is_visit[graph[node][i]])
			dfs(graph[node][i]);
	}
}

int main() {
	int n, m;
	int cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n + 1; i++) {
		vector<int> temp;
		graph.push_back(temp);
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i < n + 1; i++) {
		if (is_visit[i]) continue;
		dfs(i);
		cnt++;
	}
	cout << cnt;
	return 0;
}
