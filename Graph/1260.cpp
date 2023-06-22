#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int N, M;
int st;
vector<int> adj[1005];
stack<int> S;
queue<int> Q;
bool vis[1005];

void dfs1() {
	S.push(st);
	while (!S.empty()) {
		int cur = S.top();
		S.pop();
		if (vis[cur])continue;
		vis[cur] = true;
		cout << cur << ' ';
		for (int i = 0; i < adj[cur].size(); i++) {
			int nxt = (adj[cur][adj[cur].size() - 1 - i]);
			if (vis[nxt])continue;
			S.push(nxt);
		}
	}
}


void dfs2(int cur) {
	vis[cur] = true;
	cout << cur << ' ';
	for (auto nxt : adj[cur]) {
		if (vis[nxt]) continue;
		dfs2(nxt);
	}
}
void bfs() {
	Q.push(st);
	vis[st] = true;
	while (!Q.empty()) {
		int cur = Q.front();
		cout << cur << ' ';
		Q.pop();
		for (auto nxt : adj[cur]) {
			if (vis[nxt]) continue;
			Q.push(nxt);
			vis[nxt] = true;
		}
	}

}

int main(void) {
	ios::sync_with_stdio(false);

	cin >> N >> M >> st;
	while (M--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	dfs2(st);
	cout << '\n';
	fill(vis + 1, vis + N + 1, 0);
	bfs();
}