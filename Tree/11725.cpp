#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
int N;
int p[100005];
vector<int> adj[100005];

void bfs(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto nxt : adj[cur]) {
			if (p[cur] == nxt) continue;
			q.push(nxt);
			p[nxt] = cur;
		}
	}
}
void dfs1(int root) {
	stack<int> s;
	s.push(root);
	while (!s.empty()) {
		int cur = s.top();
		s.pop();
		for (auto nxt : adj[cur]) {
			if (p[cur] == nxt)continue;
			s.push(nxt);
			p[nxt] = cur;
		}
	}
}


void dfs2(int cur) {
	for (int nxt : adj[cur]) {
		if (p[cur] == nxt)continue;
		p[nxt] = cur;
		dfs2(nxt);
	}
}



int main(void) {
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs2(1);
	for (int i = 2; i <= N; i++) {
		cout << p[i] << '\n';
	}
}